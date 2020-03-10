#include<stdio.h>
#include<stdlib.h>
#include"TAD_lista.h"

Lista* cria_lista()
{
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(*li != NULL)
        *li = NULL;

    return li;
}

void insere_lista(Lista* li, int x, int y)
{
    //Colocar algum tipo de consistência para os valores de x e y?

    Nodo *no = (Nodo*) malloc(sizeof(Nodo));

    if(no != NULL)
    {
        no->prox = (*li);
        no->x = x;
        no->y = y;

        (*li) = no;
    }

}

void libera_lista(Lista* li)
{
    if(*li == NULL)
        return;

    Nodo *aux = (*li)->prox;

    while((*li) != NULL)
    {
        aux = *li;
        (*li) = (*li)->prox;
        free(aux);
    }

    free(li);
}
