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

Nodo* consulta_lista_pos(Lista* li, int pos)
{
    if (li == NULL || pos < 0)
        return NULL;

    Nodo* no;
    no = (*li);

    int i = 0;
    while (no != NULL && i < pos)
	{
        no = no->ant;
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

int insere_lista(Lista* li, int x, int y)
{
    //Insere logo no início da lista, já que a ordenação é feita depois
    if (li == NULL)
        return ERRO;

    Nodo *no;
    no = (Nodo*) malloc(sizeof(Nodo));

    no->x = x;
    no->y = y;

    if ((*li) == NULL)
	{   //lista vazia
        no->ant = NULL;
        no->prox = NULL;
        *li = no;
	}
    else
    {
        no->prox = (*li);
        no->ant = (*li)->ant;
        if((*li)->ant != NULL) //Apesar de que não está previsto mudar o LI do primeiro nodo
            (*li)->ant->prox = no; //Vamos ter cautela na hora de realizar esta operação
        (*li)->ant = no;
    }
    return OK;
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
