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

void libera_lista(Lista* li)
{
    if (li != NULL)
	{
        Elem* no;
        while ((*li) != NULL)
		{
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

Elem* consulta_lista_pos(Lista* li, int pos)
{
    if (li == NULL || pos < 0)
        return NULL;
    Elem* no;
    no = (*li);
    int i = 0;
    while (no != NULL && i < pos)
	{
        no = no->prox;
        i++;
    }
    if (no == NULL){
        return NULL;
    }
    else
	{
        return no;
    }
}

int insere_lista_final(Lista* li, Tipo_Dado dt)
{
    Elem *no;

    if (li == NULL) return ERRO;
    no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL)  return ERRO;

    no->dado = dt;
    no->prox = NULL;

	if ((*li) == NULL)
	{   //lista vazia: insere inicio
        no->ant = NULL;
        *li = no;
    }else
	{
        Elem *aux;
        aux = *li;
        while (aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
        no->ant = aux;
    }
    return OK;
}
int insere_lista(Lista* li, Tipo_Dado dt) {
    //Insere atras do *li.
    Elem *no;
    if (li == NULL) return ERRO;
    no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL)  return ERRO;

    no->dado = dt;

    if ((*li) == NULL)
	{   //lista vazia: insere inicio
        no->ant = NULL;
        no->prox = NULL;
        *li = no;
	}

    else {
        no->prox = (*li);
        no->ant = (*li)->ant;
        if((*li)->ant != NULL) //Se nao estiver no comeco, o de tras aponta pra ele
            (*li)->ant->prox = no;
        (*li)->ant = no;
    }
    return OK;
}

void imprime_lista(Lista* li)
{
    Elem* no = *li;

    if (li == NULL)
        return;
    while (no != NULL)
    {
        //printf("Dado: %5d # Ant: %p - Dado: %p - Prox: %p\n",no->dado,no->ant,no,no->prox);
        printf("%d %d\n",no->dado.x,no->dado.y);
        no = no->prox;
    }
}
