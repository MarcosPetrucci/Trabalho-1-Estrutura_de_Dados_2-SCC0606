#include <stdio.h>
#include <stdlib.h>

#include "mergesort.h"

void mergeArray(Lista* vetor, int inicio, int meio, int fim) {
    Nodo *vetor_aux = (Nodo*) malloc((fim-inicio)*sizeof(Nodo));
    Nodo *noEsq, *noDir;
    int esq = inicio, dir = meio;
    int i = 0;
    noEsq = consulta_lista_pos(vetor, esq);
    noDir = consulta_lista_pos(vetor, dir);

    //Vai recolocando ordenadamente no vetor_aux
    for(i=0; esq < meio && dir < fim; i++) {
        if(noEsq->x < noDir->x || (noEsq->x == noDir->x && noEsq->y <= noDir->y)) {
            vetor_aux[i] = *noEsq;
            esq++;
            noEsq = noEsq->prox;
        }
        else {
            vetor_aux[i] = *noDir;
            dir++;
            noDir = noDir->prox;
        }
    }
    //Coloca o restante do lado que sobrou dentro do auxiliar
    for( ; esq < meio; i++, esq++) {
        vetor_aux[i] = *noEsq;
        noEsq = noEsq->prox;
    }
    for( ;dir < fim; i++, dir++) {
        vetor_aux[i] = *noDir;
        noDir = noDir->prox;
    }

    //Aplica as mudancas do vetor_aux para o vetor principal
    Nodo* no;
    for (i = inicio; i < fim; i++){
        no = consulta_lista_pos(vetor, i);
        no->x = vetor_aux[i-inicio].x;
        no->y = vetor_aux[i-inicio].y;
    }

    free(vetor_aux);
}
void mergeSort(Lista* vetor, int inicio, int fim) {
    if(inicio<fim-1) {
        int meio = (inicio+fim)/2;
        //Divide ao meio da esquerda
        mergeSort(vetor, inicio, meio); //Inicio at� meio-1 = esquerda

        //Divide ao meio da direita
        mergeSort(vetor, meio, fim); //Meio at� fim = direita

        //Junta os meios
        mergeArray(vetor, inicio, meio, fim);
    }
}
