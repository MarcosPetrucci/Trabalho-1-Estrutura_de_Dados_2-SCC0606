#include <stdio.h>
#include <stdlib.h>

#include "prototipos.h"

Lista* cria_lista()
{
    extern int contagem;

    contagem+=2;
    Lista* li = (Lista*) malloc(sizeof(Lista));

    contagem++;
    if (li != NULL){
        *li = NULL;contagem++;
    }
    return li;
}

int insere_lista(Lista* li, Tipo_Dado dt) 
{
    //Insere atras do *li.
    Nodo *no;

    extern int contagem;

    contagem++;
    if (li == NULL) return ERRO;
    
    contagem+=3;
    no = (Nodo*) malloc(sizeof(Nodo));
    if (no == NULL)  return ERRO;

    contagem++;
    no->dado = dt;

    contagem++;
    if ((*li) == NULL)
	{   //lista vazia: insere inicio
        contagem+=3;
        no->ant = NULL;
        no->prox = NULL;
        *li = no;
	}

    else 
    {
        contagem+=4;
        no->prox = (*li);
        no->ant = (*li)->ant;
        (*li)->ant = no;
        *li = no;        
    }
    return OK;
}

Nodo* consulta_lista_pos(Lista* li, int pos)
{

    extern int contagem;

    contagem+=2;
    if (li == NULL || pos < 0)
        return NULL;
    
    Nodo* no;
    no = (*li); contagem++;

    int i = 0; contagem++;

    contagem+=2; // ultima comparacao do while
    while (no != NULL && i < pos)
	{
        contagem+=5;
        no = no->prox;
        i++;
    }
    
    contagem++;
    if (no == NULL)
        return NULL;
    else
        return no;
}

void imprime_lista(Lista* li, int count)
{
    extern int contagem;

    Nodo* no = *li; contagem++;

    contagem++;
    if (li == NULL)
        return;

    contagem++;
    printf("Total: %d\n",count);

    contagem++; // ultima comparacao
    while (no != NULL)
    {
        contagem+=3;
        printf("%d %d\n",no->dado.x,no->dado.y);
        no = no->prox;
    }
}

void libera_lista(Lista* li)
{
    extern int contagem;

    contagem++;
    if (li != NULL)
	{
        Nodo* no;

        contagem++;
        while ((*li) != NULL)
		{
            contagem+=4;
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li); contagem++;
    }
}
