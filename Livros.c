#include <stdio.h>
#include <string.h> // Necessário para a função strcpy()
#include "Livros.h"

//FUNÇÃO PARA CRIAR UM LIVRO
Livro criarLivro(int codigo, char titulo[], char autor[], int ano, int quantidadeTotal){
    Livro livro;

    livro.codigo = codigo;
    strcpy(livro.titulo, titulo);
    strcpy(livro.autor,autor);
    livro.ano = ano;
    livro.quantidadeTotal = quantidadeTotal;
    livro.quantidadeDisponivel = quantidadeTotal;
    return livro;   
}
//FUNÇÃO PARA EXIBIR AS INFORMAÇÕES DE UM LIVRO
void exibirLivro(Livro livro) {
    printf("Codigo: %d | Titulo: %s | Autor: %s | Ano: %d | Disponiveis: %d/%d\n",
           livro.codigo, livro.titulo, livro.autor, livro.ano, 
           livro.quantidadeDisponivel, livro.quantidadeTotal);
}
//FUNÇÃO PARA OBTER O CÓDIGO DE UM LIVRO
int obterCodigoLivro ( Livro* livro ) {
    return livro->codigo;
}
//FUNÇÃO PARA OBTER A QUANTIDADE DISPONÍVEL DE UM LIVRO
int obterQuantidadeDisponivel ( Livro* livro ){
    return livro->quantidadeDisponivel;
}
//FUNÇÃO PARA EMPRESTAR UM EXEMPLAR DE UM LIVRO
void emprestarExemplar ( Livro* livro ) {
    if (livro->quantidadeDisponivel > 0) {
        livro->quantidadeDisponivel--;
        printf("Emprestimo realizado com sucesso! Exemplares disponiveis: %d\n", livro->quantidadeDisponivel);
    } else {
        printf("Desculpe, nao ha exemplares disponiveis para emprestimo.\n");
    }
}
//FUNÇÃO PARA DEVOLVER UM EXEMPLAR DE UM LIVRO
void devolverExemplar ( Livro* livro ) {
    if(livro->quantidadeDisponivel < livro->quantidadeTotal){
        livro->quantidadeDisponivel++;
        printf("Devolucao realizada com sucesso! Exemplares disponiveis: %d\n", livro->quantidadeDisponivel);
    } else {
        printf("Erro: A quantidade disponivel ja esta no maximo. Verifique o cadastro do livro.\n"); 
    }
}
