#include <stdio.h>
#include <stdlib.h>
#include "TAD_lista.h"
#define ERRO 0
#define OK 1

Lista* cria_lista()
{
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if (li != NULL)
        *li = NULL;
    return li;
}

int insere_lista(Lista* li, Tipo_Dado dt) 
{
    //Insere logo no início da lista, já que a ordenação é feita depois
    if (li == NULL) 
        return ERRO;

    Nodo *no;
    no = (Nodo*) malloc(sizeof(Nodo));

    no->dado = dt;

    if ((*li) == NULL)
	{   //lista vazia
        no->ant = NULL;
        no->prox = NULL;
        *li = no;
	}
    else 
    {
        no->prox = (*li);
        no->ant = NULL;
        (*li)->ant = no;
        (*li) = no;
    }
    return OK;
}

Nodo* consulta_lista_pos(Lista* li, int pos)
{
    if (li == NULL || pos < 0)
        return NULL;

    Nodo *no = (Nodo*) malloc(sizeof(no));
    no = (*li);
    
    int i = 0;
    while (no != NULL && i < pos)
	{
        no = no->prox;
        i++;
    }
    if (no == NULL)
    {
        return NULL;
    }
    else
	{
        return no;
    }
}

int conta_tamanho(Lista* li)
{
    if((*li) == NULL)  
        return ERRO;

    int tam = 0;

    Nodo *no;
    no = (*li);

    while(no != NULL)
    {
        tam++;
        no = no->prox;
    }

    return tam;
}

void imprime_lista(Lista* li)
{
    printf("Total: %d\n", conta_tamanho(li));

    Nodo* no;
    no = (*li);

    while(no != NULL)
    {
        printf("%d %d\n", no->dado.x, no->dado.y);
        no = no->prox;
    }
}

void libera_lista(Lista* li)
{
    if (li != NULL)
	{
        Nodo* no;
        while ((*li) != NULL)
		{
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}