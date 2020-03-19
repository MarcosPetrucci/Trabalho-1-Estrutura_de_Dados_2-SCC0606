#include <stdio.h>
#include <stdlib.h>

#include "prototipos.h"

// ------ Algoritmo de ordenação recursivo merge sort --------//

void mergeArray(Lista* vetor, int inicio, int meio, int fim) 
{
    extern int contagem;

    contagem+=2;
    Nodo *vetor_aux = (Nodo*) malloc((fim-inicio)*sizeof(Nodo));
    Nodo *noEsq, *noDir;

    contagem+=3;
    int esq = inicio, dir = meio;
    int i = 0;

    contagem+=4;
    noEsq = consulta_lista_pos(vetor, esq);
    noDir = consulta_lista_pos(vetor, dir);

    //Vai recolocando ordenadamente no vetor_aux

    contagem+=3; // inicializacao e ultima comparacao
    for(i = 0; esq < meio && dir < fim; i++) {
        contagem+=4;

        contagem+=3;
        if(noEsq->dado.x < noDir->dado.x || (noEsq->dado.x == noDir->dado.x && noEsq->dado.y <= noDir->dado.y)) {
            contagem+=4;
            vetor_aux[i] = *noEsq;
            esq++;
            noEsq = noEsq->prox;
        }
        else {
            contagem+=4;
            vetor_aux[i] = *noDir;
            dir++;
            noDir = noDir->prox;
        }
    }
    //Coloca o restante do lado que sobrou dentro do auxiliar

    contagem++; // ultima comparacao
    for( ; esq < meio; i++, esq++) {
        contagem+=7;
        vetor_aux[i] = *noEsq;
        noEsq = noEsq->prox;
    }
    contagem++;
    for( ;dir < fim; i++, dir++) {
        contagem+=7;
        vetor_aux[i] = *noDir;
        noDir = noDir->prox;
    }

    //Aplica as mudancas do vetor_aux para o vetor principal
    Nodo* no;
    contagem+=2;
    for (i = inicio; i < fim; i++){
        contagem+=7;

        if(i == inicio)
            no = consulta_lista_pos(vetor, i);
        else
            no = no->prox;
        no->dado.x = vetor_aux[i-inicio].dado.x;
        no->dado.y = vetor_aux[i-inicio].dado.y;
    }
    
    contagem++;
    free(vetor_aux);
}

void mergeSort(Lista* vetor, int inicio, int fim) 
{
    extern int contagem;

    contagem++;
    if(inicio<fim-1)
     {
        contagem+=3;
        int meio = (inicio+fim)/2;
        //Divide ao meio da esquerda
        mergeSort(vetor, inicio, meio); //Inicio at� meio-1 = esquerda
        contagem++;

        //Divide ao meio da direita
        mergeSort(vetor, meio, fim); //Meio at� fim = direita
        contagem++;

        //Junta os meios
        mergeArray(vetor, inicio, meio, fim);
        contagem++;
    }
}
