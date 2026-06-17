#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "livros.h"
#include "arvore.h"
#include "fila.h"
#include "lista.h" 


int main() {
    int opcao;
    
    Arvore *arvore = criarArvore();
    Fila *filaReservas = criarFila();
    Lista *historico = CriarLista();

    do {
        printf("\n=================================================\n");
        printf("      SISTEMA DE GERENCIAMENTO DE BIBLIOTECA       \n");
        printf("=================================================\n");
        printf("1. Cadastrar novo livro\n");
        printf("2. Buscar livro por codigo\n");
        printf("3. Listar livros em ordem crescente de codigo\n");
        printf("4. Listar livros em pre-ordem\n");
        printf("5. Listar livros em pos-ordem\n");
        printf("6. Realizar emprestimo de livro\n");
        printf("7. Devolver livro\n");
        printf("8. Exibir fila de reservas\n");
        printf("9. Exibir historico de emprestimos\n");
        printf("10. Exibir quantidade de livros cadastrados\n");
        printf("11. Exibir altura da arvore\n");
        printf("0. Sair\n");
        printf("=================================================\n");
        printf("Escolha uma opcao: ");
        
        if (scanf("%d", &opcao) != 1) {
            while (getchar() != '\n');
            opcao = -1;
        }

        switch(opcao) {
            case 1: {
                printf("\n--- Cadastrar Novo Livro ---\n");
                int codigo;
                printf("Digite o codigo do livro: ");
                scanf("%d", &codigo);
                
                // Regra: Não aceitar dois livros com o mesmo código
                Livro* busca = buscarLivroArvore(arvore, codigo);
                if (busca != NULL) {
                    printf("Erro: Ja existe um livro cadastrado com o codigo %d!\n", codigo);
                } else {
                    char titulo[100], autor[100];
                    int ano, quantidade;
                    
                    while (getchar() != '\n'); // Limpar o buffer
                    
                    printf("Digite o titulo: ");
                    scanf(" %[^\n]s", titulo); // Lê a string mesmo com espaços
                    
                    printf("Digite o autor: ");
                    scanf(" %[^\n]s", autor);
                    
                    printf("Digite o ano de publicacao: ");
                    scanf("%d", &ano);
                    
                    printf("Digite a quantidade total de exemplares: ");
                    scanf("%d", &quantidade);
                    
                    Livro novoLivro = criarLivro(codigo, titulo, autor, ano, quantidade);
                    inserirLivroArvore(arvore, &novoLivro);
                    
                    printf("\nSucesso: Livro '%s' cadastrado com sucesso!\n", titulo);
                }
                break;
            }
            case 2: {
                printf("\n--- Buscar Livro por Codigo ---\n");
                int codigo;
                printf("Digite o codigo do livro: ");
                scanf("%d", &codigo);
                
                Livro* livro = buscarLivroArvore(arvore, codigo);
                if (livro != NULL) {
                    printf("\nLivro Encontrado:\n");
                    exibirLivro(*livro);
                } else {
                    printf("\nErro: Livro com codigo %d nao encontrado.\n", codigo);
                }
                break;
            }
            case 3: {
                printf("\n--- Listar Livros em Ordem Crescente ---\n");
                listarLivrosEmOrdem(arvore);
                break;
            }
            case 4: {
                printf("\n--- Listar Livros em Pre-Ordem ---\n");
                listarLivrosPreOrdem(arvore);
                break;
            }
            case 5: {
                printf("\n--- Listar Livros em Pos-Ordem ---\n");
                listarLivrosPosOrdem(arvore);
                break;
            }
            case 6: {
                printf("\n--- Realizar Emprestimo ---\n");
                int codigo;
                char nome[100];
                
                while (getchar() != '\n'); // Limpar o buffer
                printf("Digite o nome do usuario: ");
                scanf(" %[^\n]s", nome);
                
                printf("Digite o codigo do livro: ");
                scanf("%d", &codigo);
                
                Livro* livro = buscarLivroArvore(arvore, codigo);
                if (livro == NULL) {
                    printf("Erro: Livro nao encontrado no acervo.\n");
                } else {
                    // Integração Empréstimo e Fila
                    if (livro->quantidadeDisponivel > 0) {
                        emprestarExemplar(livro);
                        
                        // Registar no Histórico (Integração com a Lista)
                        Emprestimo emp;
                        emp.codigoLivro = codigo;
                        strcpy(emp.nomeUsuario, nome);
                        strcpy(emp.tituloLivro, livro->titulo);
                        InserirEmprestimo(historico, emp);
                        
                    } else {
                        printf("\nAtencao: Nao ha exemplares disponiveis de '%s'.\n", livro->titulo);
                        printf("Deseja entrar na fila de reservas? (1 - Sim / 0 - Nao): ");
                        int resposta;
                        scanf("%d", &resposta);
                        
                        if (resposta == 1) {
                            Reserva res;
                            res.codigoLivro = codigo;
                            strcpy(res.nomeUsuario, nome);
                            enfileirarReserva(filaReservas, res);
                            printf("Sucesso: Usuario %s adicionado a fila de reservas!\n", nome);
                        }
                    }
                }
                break;
            }
            case 7: {
                printf("\n--- Devolver Livro ---\n");
                int codigo;
                printf("Digite o codigo do livro a ser devolvido: ");
                scanf("%d", &codigo);
                
                Livro* livro = buscarLivroArvore(arvore, codigo);
                if (livro == NULL) {
                    printf("Erro: Livro nao encontrado no acervo.\n");
                } else {
                    devolverExemplar(livro);
                    printf("\nAviso: Verifique se ha usuarios na fila de reservas aguardando por este livro.\n");
                    // O PDF pede como versão mínima apenas a exibição da fila.
                    exibirReservas(filaReservas);
                }
                break;
            }
            case 8: {
                exibirReservas(filaReservas);
                break;
            }
            case 9: {
                ListarEmprestimos(historico);
                break;
            }
            case 10: {
                int total = contarLivros(arvore);
                printf("\nQuantidade de livros (titulos diferentes) cadastrados: %d\n", total);
                break;
            }
            case 11: {
                int altura = calcularAlturaArvore(arvore);
                printf("\nA altura atual da Arvore Binaria de Busca e: %d\n", altura);
                break;
            }
            case 0: {
                printf("\nEncerrando o sistema. Muito obrigado e ate a proxima!\n");
                break;
            }
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}