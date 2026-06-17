#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include <string.h>
#include "Livros.h"

//DEFINIÇÃO DAS FUNÇÕES

Lista *CriarLista() {
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    lista->inicio = NULL;
    return lista;
}

void InserirEmprestimo(Lista *lista, Emprestimo emprestimo) {
    NoLista *novoNo = (NoLista *)malloc(sizeof(NoLista));

    if (novoNo == NULL) {
        printf("Erro de memoria!\n");
        return;
    }

    novoNo->emprestimo = emprestimo;
    novoNo->proximo = lista->inicio;
    lista->inicio = novoNo;
}

void ListarEmprestimos(Lista *lista) {
    if (lista->inicio == NULL) {
        printf("\nNenhum emprestimo no historico.\n");
        return;
    }
    
    printf("\n--- Historico de Emprestimos ---\n");

    NoLista *atual = lista->inicio;

    while(atual != NULL){
        printf("Usuario %s | Livro: %s (Codigo: %d)\n",
        atual->emprestimo.nomeUsuario,
        atual->emprestimo.tituloLivro,
        atual->emprestimo.codigoLivro);

        atual = atual->proximo;
    }
}

int ListaVazia(Lista *lista){
    return (lista->inicio == NULL);
}
