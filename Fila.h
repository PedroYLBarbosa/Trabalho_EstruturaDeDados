#ifdef FILA_H
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

#endif