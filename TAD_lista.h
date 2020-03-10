#include<stdio.h>

struct elem
{
    int x;
    int y;

    struct elem *prox;
    struct elem *ant;
};

typedef struct elem* Lista;
typedef struct elem Nodo;

Lista* cria_lista();

//Posso fazer o insere_lista retornar um ponteiro para o último elemento adicionado, o guerreiro mencionou isso
int insere_lista(Lista* li, int x, int y);
Nodo* consulta_lista_pos(Lista* li, int pos);
int conta_tamanho(Lista* li);
void imprime_resultados(Lista* li);
void libera_lista(Lista* li);