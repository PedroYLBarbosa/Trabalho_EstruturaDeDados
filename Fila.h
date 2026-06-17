#ifndef FILA_H
#define FILA_H

typedef struct Reserva {
    int codigoLivro;
    char nomeUsuario[100];
} Reserva;

typedef struct NoFila {
    Reserva reserva;
    struct NoFila *proximo;
} NoFila;

typedef struct Fila{
    NoFila *inicio;
    NoFila *fim;
} Fila;

//ASSINATURA DAS FUNÇÕES
Fila * criarFila () ;
void enfileirarReserva ( Fila * fila , Reserva reserva );
Reserva desenfileirarReserva(Fila *fila); 
int filaVazia ( Fila * fila ) ;
void exibirReservas ( Fila * fila );
#endif