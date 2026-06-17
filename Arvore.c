#include <stdio.h>
#include <stdlib.h> 
#include "arvore.h"
#include "livros.h"

// =======================================================
// FUNÇÕES AUXILIARES (Lidam com a recursão dos nós)
// =======================================================

void listarEmOrdemAux(NoArvore *no) {
    if(no != NULL) {
        listarEmOrdemAux(no->esquerda);
        exibirLivro(no->livro); 
        listarEmOrdemAux(no->direita);
    }
}

void listarPreOrdemAux(NoArvore *no) {
    if(no != NULL) {
        exibirLivro(no->livro);
        listarPreOrdemAux(no->esquerda);
        listarPreOrdemAux(no->direita);
    }
}

void listarPosOrdemAux(NoArvore *no) {
    if(no != NULL) {
        listarPosOrdemAux(no->esquerda);
        listarPosOrdemAux(no->direita);
        exibirLivro(no->livro);
    }
}

int contarLivrosAux(NoArvore *no) {
    if (no == NULL) {
        return 0;
    }
    return 1 + contarLivrosAux(no->esquerda) + contarLivrosAux(no->direita);
}

int calcularAlturaAux(NoArvore *no) {
    if (no == NULL) {
        return -1;
    }
    int alturaEsquerda = calcularAlturaAux(no->esquerda);
    int alturaDireita = calcularAlturaAux(no->direita);
    return 1 + (alturaEsquerda > alturaDireita ? alturaEsquerda : alturaDireita);
}

// =======================================================
// FUNÇÕES PRINCIPAIS (Assinaturas exigidas no Classroom)
// =======================================================

Arvore* criarArvore() {
    Arvore *arvore = (Arvore*) malloc(sizeof(Arvore));
    if (arvore != NULL) {
        arvore->raiz = NULL;
    }
    return arvore;
}

// Atualizado para receber Livro* livro
void inserirLivroArvore(Arvore *arvore, Livro *livro) {
    // 1. Declaramos TODAS as variáveis no topo da função (Padrão C Clássico)
    NoArvore *novoNo = (NoArvore*) malloc(sizeof(NoArvore));
    NoArvore *atual = NULL; 
    NoArvore *pai = NULL;   

    // Verifica se a memória foi alocada com sucesso
    if (novoNo == NULL) {
        printf("Erro de memoria!\n");
        return;
    }

    // Copia todos os dados do livro apontado para dentro do nó
    novoNo->livro = *livro; 
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;

    // 2. Lógica de inserção
    if(arvore->raiz == NULL){
        arvore->raiz = novoNo;
    } else {
        // Agora apenas usamos o 'atual' que já foi criado lá em cima
        atual = arvore->raiz; 

        while(atual != NULL){
            pai = atual;
            
            if(livro->codigo < atual->livro.codigo){ 
                atual = atual->esquerda;
            } else {
                atual = atual->direita;
            }
        }
        
        if(livro->codigo < pai->livro.codigo){
            pai->esquerda = novoNo;
        } else {
            pai->direita = novoNo;
        }
    }
}
Livro* buscarLivroArvore(Arvore *arvore, int codigo) {
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

void listarLivrosEmOrdem(Arvore *arvore) {
    if (arvore != NULL) listarEmOrdemAux(arvore->raiz);
}

void listarLivrosPreOrdem(Arvore *arvore) {
    if (arvore != NULL) listarPreOrdemAux(arvore->raiz);
}

void listarLivrosPosOrdem(Arvore *arvore) {
    if (arvore != NULL) listarPosOrdemAux(arvore->raiz);
}

int contarLivros(Arvore* arvore) {
    if (arvore == NULL || arvore->raiz == NULL) {
        return 0;
    }
    return contarLivrosAux(arvore->raiz);
}

int calcularAlturaArvore(Arvore* arvore) {
    if (arvore == NULL || arvore->raiz == NULL) {
        return -1;
    }
    // Chama a auxiliar!
    return calcularAlturaAux(arvore->raiz); 
}