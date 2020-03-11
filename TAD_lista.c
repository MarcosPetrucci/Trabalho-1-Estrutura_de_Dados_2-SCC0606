#include <stdio.h>
#include <stdlib.h>

#include "prototipos.h"

Lista* cria_lista()
{
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if (li != NULL)
        *li = NULL;
    return li;
}

int insere_lista(Lista* li, Tipo_Dado dt) 
{
    //Insere atras do *li.
    Nodo *no;
    if (li == NULL) return ERRO;
    
    no = (Nodo*) malloc(sizeof(Nodo));
    if (no == NULL)  return ERRO;

    no->dado = dt;

    if ((*li) == NULL)
	{   //lista vazia: insere inicio
        no->ant = NULL;
        no->prox = NULL;
        *li = no;
	}

    else 
    {
        no->prox = (*li);
        no->ant = (*li)->ant;
        (*li)->ant = no;
        *li = no;        
    }
    return OK;
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
        no = no->prox;
        i++;
    }
    
    if (no == NULL)
        return NULL;
    else
        return no;
}

void imprime_lista(Lista* li, int count)
{
    Nodo* no = *li;

    if (li == NULL)
        return;

    printf("Total: %d\n",count);
    while (no != NULL)
    {
        printf("%d %d\n",no->dado.x,no->dado.y);
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
