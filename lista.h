#ifndef LISTA_H
#define LISTA_H
#include "livros.h"

typedef struct Emprestimo {
    int codigoLivro;
    char nomeUsuario[100];
    char tituloLivro[100];
} Emprestimo;

typedef struct NoLista {
    Emprestimo emprestimo;
    struct NoLista *proximo;
} NoLista;

typedef struct Lista {
    NoLista *inicio;
} Lista;

//ASSINATURA DAS FUNÇÕES
Lista* CriarLista () ;
void InserirEmprestimo ( Lista *lista , Emprestimo emprestimo );
void ListarEmprestimos ( Lista *lista );
int ListaVazia ( Lista *lista );

#endif