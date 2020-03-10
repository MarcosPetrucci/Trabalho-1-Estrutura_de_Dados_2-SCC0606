#include<stdio.h>

struct elem
{
    int x;
    int y;

    struct elem *prox;
};

typedef struct elem* Lista;
typedef struct elem Nodo;

Lista* cria_lista();

//Posso fazer o insere_lista retornar um ponteiro para o último elemento adicionado, o guerreiro mencionou isso
void insere_lista(Lista* li, int x, int y);
void ordena_lista(Lista* li);
Nodo* ultimo_nodo(Lista* li);
void libera_lista(Lista* li);