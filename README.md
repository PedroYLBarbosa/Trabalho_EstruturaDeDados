📚 Sistema de Gestão de Biblioteca

Projeto académico desenvolvido em linguagem C para a disciplina de Estruturas de Dados. Este sistema em modo de consola (terminal) permite a gestão completa de uma biblioteca, incluindo o acervo de livros, o controlo de empréstimos e a gestão de filas de espera.

🚀 Funcionalidades

O sistema possui um menu interativo com as seguintes funcionalidades:

Cadastro e Busca: Adicionar novos livros ao acervo e procurar livros específicos através do seu código.

Listagem do Acervo: Visualizar os livros em diferentes percursos (Ordem Crescente, Pré-ordem e Pós-ordem).

Empréstimo e Devolução: Controlo automático da quantidade de exemplares disponíveis.

Fila de Reservas: Caso um livro não tenha exemplares disponíveis, o utilizador pode entrar numa lista de espera.

Histórico: Registo cronológico de todos os empréstimos realizados.

Estatísticas: Contagem total de títulos únicos e cálculo da altura atual da árvore estrutural.

🧠 Estruturas de Dados Utilizadas

Para garantir a eficiência e a organização, o projeto foi modularizado em diferentes Tipos Abstratos de Dados (TADs), cada um resolvendo um problema específico:

Árvore Binária de Busca (ABB) - arvore.c / arvore.h

Uso: Armazenamento do acervo de livros.

Porquê: Permite buscas rápidas e mantém os livros naturalmente ordenados pelo código.

Lista Encadeada Simples - lista.c / lista.h

Uso: Registo do histórico de empréstimos.

Porquê: Inserções no início da lista (O(1)) garantem que os empréstimos mais recentes apareçam sempre no topo de forma muito rápida.

Fila (Queue) - fila.c / fila.h

Uso: Controlo da lista de espera para livros sem stock.

Porquê: Segue a rigorosa política FIFO (First-In, First-Out), garantindo que o primeiro utilizador a reservar seja o primeiro a receber o livro quando este for devolvido.

TAD Livro - livros.c / livros.h

Uso: Estrutura base que contém os dados de cada obra (código, título, autor, ano, quantidade total e disponível).

🛠️ Como Compilar e Executar

Certifique-se de que tem o compilador GCC instalado na sua máquina.

1. Compilar o projeto:
No terminal, navegue até à pasta do projeto e execute o seguinte comando para compilar todos os ficheiros .c juntos:

gcc *.c -o biblioteca


2. Executar o sistema:
Após a compilação, inicie o programa com o comando:

No Windows:

.\biblioteca.exe


No Linux / macOS:

./biblioteca


👨‍💻 Autor 

Desenvolvido por Pedro Yago como projeto de avaliação para a disciplina de Estruturas de Dados.