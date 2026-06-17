#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

// 1. Criar a Fila (Âncora)
Fila* criarFila() {
    Fila *fila = (Fila*) malloc(sizeof(Fila));
    if (fila != NULL) {
        fila->inicio = NULL;
        fila->fim = NULL;
    }
    return fila;
}

// 2. Verificar se está vazia (Complexidade O(1))
int filaVazia(Fila *fila) {
    if (fila == NULL) return 1;
    return (fila->inicio == NULL);
}

// 3. ENFILEIRAR: Inserir no FINAL da fila (Complexidade O(1))
void enfileirarReserva(Fila *fila, Reserva reserva) {
    // Fabrica a caixinha
    NoFila *novoNo = (NoFila*) malloc(sizeof(NoFila));
    if (novoNo == NULL) {
        printf("Erro: Memoria insuficiente!\n");
        return;
    }
    
    // Preenche com os dados da reserva
    novoNo->reserva = reserva;
    novoNo->proximo = NULL; // Como vai para o fim, não tem ninguém depois dele

    // Lógica de ligação FIFO
    if (filaVazia(fila)) {
        // Se a fila estava vazia, o novo nó é o primeiro e o último ao mesmo tempo
        fila->inicio = novoNo;
    } else {
        // Se já tem gente, o atual último da fila aponta para o novo nó
        fila->fim->proximo = novoNo;
    }
    // A âncora "fim" é atualizada para este novo nó
    fila->fim = novoNo;
}

// 4. DESENFILEIRAR: Remover do INÍCIO da fila (Complexidade O(1))
Reserva desenfileirarReserva(Fila *fila) {
    Reserva reservaVazia = {-1, ""}; // Usado para retornar caso dê erro

    if (filaVazia(fila)) {
        return reservaVazia;
    }

    // Salva o primeiro nó e a informação dele numa variável temporária
    NoFila *temp = fila->inicio;
    Reserva reservaAtendida = temp->reserva;

    // A fila avança: o início passa a ser o segundo da fila
    fila->inicio = fila->inicio->proximo;

    // Se a fila ficou vazia após remover este, precisamos limpar o "fim" também
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    // Liberta a memória (destrói a caixinha)
    free(temp); 
    
    return reservaAtendida;
}

// 5. Exibir todas as reservas
void exibirReservas(Fila *fila) {
    if (filaVazia(fila)) {
        printf("\nNao ha reservas na fila.\n");
        return;
    }

    printf("\n--- Fila de Reservas ---\n");
    NoFila *atual = fila->inicio;
    int posicao = 1;

    while (atual != NULL) {
        printf("%d. Usuario: %s | Codigo do Livro: %d\n", 
               posicao, atual->reserva.nomeUsuario, atual->reserva.codigoLivro);
        atual = atual->proximo;
        posicao++;
    }
    printf("------------------------\n");
}