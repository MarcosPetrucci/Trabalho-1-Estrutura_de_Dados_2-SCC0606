#include <stdio.h>
#include <stdlib.h>

#include "mergesort.h"

void mergeArray(Lista* vetor, int inicio, int meio, int fim) {
    int *vetor_aux = (int*) malloc((fim-inicio)*sizeof(int));;
    int esq = inicio, dir = meio;
    int i = 0;

    //Vai recolocando ordenadamente no vetor_aux
    for(i=0; esq < meio && dir < fim; i++) {
        if ((*consulta_lista_pos(vetor, esq))->dado <= (*consulta_lista_pos(vetor, dir))->dado)
            vetor_aux[i] = (*consulta_lista_pos(vetor, esq++))->dado;
        else
            vetor_aux[i] = (*consulta_lista_pos(vetor, dir++))->dado;
    }
    //Coloca o restante do lado que sobrou dentro do auxiliar
    for( ; esq < meio; i++, esq++)
        vetor_aux[i] = (*consulta_lista_pos(vetor, esq))->dado;
    for( ;dir < fim; i++, dir++)
        vetor_aux[i] = (*consulta_lista_pos(vetor, dir))->dado;

    //Aplica as mudancas do vetor_aux para o vetor principal
    for (i = inicio; i < fim; i++)
        (*consulta_lista_pos(vetor, i))->dado = vetor_aux[i-inicio];

    free(vetor_aux);
}
void mergeSort(Lista* vetor, int inicio, int fim) {
    if(inicio<fim-1) {
        int meio = (inicio+fim)/2;
        //Divide ao meio da esquerda
        mergeSort(vetor, inicio, meio); //Inicio até meio-1 = esquerda

        //Divide ao meio da direita
        mergeSort(vetor, meio, fim); //Meio até fim = direita

        //Junta os meios
        mergeArray(vetor, inicio, meio, fim);
    }
}
