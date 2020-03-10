#include <stdio.h>
#include <stdlib.h>
#include "TAD_lista.h" //inclui os Prot�tipos

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

Lista* consulta_lista_pos(Lista* li, int pos)
{
    if (li == NULL || pos < 0)
        return NULL;
    Lista *no = cria_lista();
    (*no) = (*li);
    int i = 0;
    while ((*no) != NULL && i < pos)
	{
        (*no) = (*no)->prox;
        i++;
    }
    if ((*no) == NULL){
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
	{   //lista vazia: insere in�cio
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
	{   //lista vazia: insere in�cio
        no->ant = NULL;
        no->prox = NULL;
        *li = no;
	}
    else {
        no->prox = (*li);
        no->ant = (*li)->ant;
        if((*li)->ant != NULL) //Se n�o estiver no comeco, o de tras aponta pra ele
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
        printf("Dado: %5d # Ant: %p - Dado: %p - Prox: %p\n",no->dado,no->ant,no,no->prox);
        no = no->prox;
    }
    printf("-------------- FIM LISTA -----------------\n");
}
int remove_lista(Lista* li)
{   //TERMINAR
    if (li == NULL)
        return ERRO;
    if ((*li) == NULL)//lista vazia
        return ERRO;
    Elem *no = *li;
    if (no == NULL)//n�o encontrado
        return ERRO;
    if (no->ant == NULL)//remover o primeiro?
        *li = no->prox;
    else
        no->ant->prox = no->prox;

    if (no->prox != NULL)//n�o � o �ltimo?
        no->prox->ant = no->ant;

    free(no);
    return OK;
}
