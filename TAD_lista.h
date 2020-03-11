#include<stdio.h>

typedef struct{
    int x;
    int y;
}Tipo_Dado;

struct elem
{
    Tipo_Dado dado;
    struct elem *prox;
    struct elem *ant;
};

typedef struct elem* Lista;
typedef struct elem Nodo;

Lista* cria_lista();

//Posso fazer o insere_lista retornar um ponteiro para o último elemento adicionado, o guerreiro mencionou isso
int insere_lista(Lista* li, Tipo_Dado dt);
Nodo* consulta_lista_pos(Lista* li, int pos);
int conta_tamanho(Lista* li);
void imprime_lista(Lista* li);
void libera_lista(Lista* li);