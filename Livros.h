#ifndef LIVROS_H
#define LIVROS_H
typedef struct Livro{
    int codigo;
    char titulo[100];
    char autor[100];
    int ano;
    int quantidadeTotal;
    int quantidadeDisponivel;
} Livro;

//ASSINATURA DAS FUNÇÕES
Livro criarLivro(int codigo, char titulo[], char autor[], int ano, int quantidadeTotal);
void exibirLivro(Livro livro);
int obterCodigoLivro ( Livro* livro ) ;
int obterQuantidadeDisponivel ( Livro* livro ) ;
void emprestarExemplar ( Livro* livro ) ;
void devolverExemplar ( Livro* livro ) ;


#endif