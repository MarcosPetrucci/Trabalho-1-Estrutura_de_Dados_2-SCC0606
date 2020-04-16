#include <stdio.h>
#include <stdlib.h>

#include "prototipos.h"

// ------ Algoritmo de ordenação recursivo merge sort --------//

void mergeArray(int inicio, Nodo* pinicio, int meio, Nodo* pmeio, int fim) 
{
    extern int contagem;

    contagem+=2;
    Nodo *vetor_aux = (Nodo*) malloc((fim-inicio)*sizeof(Nodo));
    Nodo *noEsq, *noDir;

    contagem+=3;
    int esq = inicio, dir = meio;
    int i = 0;

    contagem+=4;
    noEsq = pinicio;
    noDir = pmeio;

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
    contagem+=3;
    for (i = inicio; i < fim; i++){
        contagem+=7;

        if(i == inicio)
            no = pinicio;
        else
            no = no->prox;

        no->dado.x = vetor_aux[i-inicio].dado.x;
        no->dado.y = vetor_aux[i-inicio].dado.y;
    }
    
    contagem++;
    free(vetor_aux);
}

void mergeSort(int inicio, Nodo* pinicio, int fim) 
{
    extern int contagem;

    contagem+=2;
    if(inicio < (fim-1))
     {
        contagem+=5;
        int meio = (inicio+fim)/2;
        Nodo* pmeio = encontrar_ponteiro(pinicio, meio-inicio);

        //Divide ao meio da esquerda
        mergeSort(inicio, pinicio, meio); //Inicio ate meio-1 = esquerda
        contagem++;

        //Divide ao meio da direita
        mergeSort(meio, pmeio, fim); //Meio ate fim = direita
        contagem++;

        //Junta os meios
        mergeArray(inicio, pinicio, meio, pmeio, fim);
        contagem++;
    }
}
