#include <stdlib.h> 
#include "Arvore.h"
#include "Livros.h"


//FUNÇÃO PARA CRIAR UMA ÁRVORE BINÁRIA DE BUSCA
Arvore* criarArvore() {
    Arvore *arvore = (Arvore*) malloc(sizeof(Arvore));
    arvore->raiz = NULL;
    return arvore;
}
//FUNÇÃO PARA INSERIR UM LIVRO NA ÁRVORE BINÁRIA DE BUSCA
void inserirLivroArvore(Arvore *arvore, Livro livro) {
    NoArvore *novoNo = (NoArvore*) malloc(sizeof(NoArvore));
    novoNo->livro = livro;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;

    if(arvore->raiz == NULL){
        arvore->raiz = novoNo;
    } else {
        NoArvore *atual = arvore->raiz;
        NoArvore *pai = NULL;

        while(atual != NULL){
            pai = atual;
            if(livro.codigo < atual->livro.codigo){
                atual = atual->esquerda;
            } else {
                atual = atual->direita;
            }
        }
        if(livro.codigo < pai->livro.codigo){
            pai->esquerda = novoNo;
        } else {
            pai->direita = novoNo;
        }
    }
}

Livro *buscarLivroArvore(Arvore *arvore, int codigo) {
    NoArvore *atual = arvore->raiz;

    while(atual != NULL){
        if(codigo == atual->livro.codigo){
            return &atual->livro;
        } else if(codigo < atual->livro.codigo){
            atual = atual->esquerda;
        } else {
            atual = atual->direita;
        }
    }
    return NULL; 
}

//FUNÇÃO PARA LISTAR OS LIVROS EM ORDEM CRESCENTE
void listarLivrosOrdem(Arvore *arvore) {
    NoArvore *atual = arvore->raiz;
    if(atual != NULL){
        listarLivrosOrdem(atual);
        printf("Código: %d, Título: %s, Autor: %s, Ano: %d, Quantidade Total: %d, Quantidade Disponível: %d\n",
               atual->livro.codigo, atual->livro.titulo, atual->livro.autor, atual->livro.ano,
               atual->livro.quantidadeTotal, atual->livro.quantidadeDisponivel);
    }
}
//FUNÇÃO PARA LISTAR OS LIVROS EM ORDEM PRÉ-ORDEM
void listarLivrosPreOrdem(NoArvore *no) {
    if(no != NULL){
        printf("Código: %d, Título: %s, Autor: %s, Ano: %d, Quantidade Total: %d, Quantidade Disponível: %d\n",
               no->livro.codigo, no->livro.titulo, no->livro.autor, no->livro.ano,
               no->livro.quantidadeTotal, no->livro.quantidadeDisponivel);
        listarLivrosPreOrdem(no->esquerda);
        listarLivrosPreOrdem(no->direita);
    }
}
//FUNÇÃO PARA LISTAR OS LIVROS EM ORDEM PÓS-ORDEM
void listarLivrosPosOrdem(NoArvore *no) {
    if(no != NULL){
        listarLivrosPosOrdem(no->esquerda);
        listarLivrosPosOrdem(no->direita);
        printf("Código: %d, Título: %s, Autor: %s, Ano: %d, Quantidade Total: %d, Quantidade Disponível: %d\n",
               no->livro.codigo, no->livro.titulo, no->livro.autor, no->livro.ano,
               no->livro.quantidadeTotal, no->livro.quantidadeDisponivel);
    }
}
//FUNÇÃO PARA CONTAR O NÚMERO TOTAL DE LIVROS NA ÁRVORE
int contarLivros ( Arvore* arvore ) {
    if (arvore->raiz == NULL) {
        return 0;
    }
    return arvore->raiz->livro.quantidadeTotal + contarLivros(arvore->raiz->esquerda) + contarLivros(arvore->raiz->direita);
}
//FUNÇÃO PARA CALCULAR A ALTURA DA ÁRVORE
int calcularAlturaArvore ( Arvore* arvore ) {
    if (arvore->raiz == NULL) {
        return -1;
    }
    int alturaEsquerda = calcularAlturaArvore(arvore->raiz->esquerda);
    int alturaDireita = calcularAlturaArvore(arvore->raiz->direita);
    return 1 + (alturaEsquerda > alturaDireita ? alturaEsquerda : alturaDireita);
}
