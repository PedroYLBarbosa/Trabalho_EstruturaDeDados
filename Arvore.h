#ifndef ARVORE_H
#define ARVORE_H

#include "Livros.h"

typedef struct NoArvore {
    Livro livro;
    struct NoArvore *esquerda;
    struct NoArvore *direita;
} NoArvore;
typedef struct Arvore{
    NoArvore *raiz;
} Arvore;

Arvore* criarArvore();
void inserirLivroArvore(Arvore *arvore, Livro livro);
Livro* buscarLivroArvore(Arvore *arvore, int codigo);

void listarLivrosCrescente(NoArvore *no);
void listarLivrosPreOrdem(NoArvore *no);
void listarLivrosPosOrdem(NoArvore *no);

int contarLivros ( Arvore * arvore );
int calcularAlturaArvore ( Arvore * arvore );

#endif