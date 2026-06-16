#include <stdio.h>
#include <stdlib.h>

// Inclusão dos seus arquivos de cabeçalho
#include "Livros.h"
#include "Arvore.h"
#include "Fila.h"
// #include "Lista.h" // Lembre-se de criar este arquivo depois!

int main() {
    int opcao;
    

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
            case 1:
                printf("\n--- Cadastrar Novo Livro ---\n");
                break;
            case 2:
                printf("\n--- Buscar Livro por Codigo ---\n");
                break;
            case 3:
                printf("\n--- Listar Livros em Ordem Crescente ---\n");
                break;
            case 4:
                printf("\n--- Listar Livros em Pre-Ordem ---\n");
                break;
            case 5:
                printf("\n--- Listar Livros em Pos-Ordem ---\n");
                break;
            case 6:
                printf("\n--- Realizar Emprestimo ---\n");
                break;
            case 7:
                printf("\n--- Devolver Livro ---\n");
                break;
            case 8:
                printf("\n--- Fila de Reservas ---\n");
                break;
            case 9:
                printf("\n--- Historico de Emprestimos ---\n");
                break;
            case 10:
                printf("\n--- Quantidade de Livros ---\n");
                break;
            case 11:
                printf("\n--- Altura da Arvore ---\n");
                break;
            case 0:
                printf("\nSaindo do sistema... Ate logo!\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}