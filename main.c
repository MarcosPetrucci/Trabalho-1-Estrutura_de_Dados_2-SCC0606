#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#include "mergesort.h"
//#include "TAD_lista.h"
#include "buscaRecursiva.h"

#define ARRAYSIZE 10

#define L 5
#define C 5

int matrix[5][5] = {{0,0,1,0,0},{0,1,0,0,0},{0,1,1,0,0},{0,0,0,0,0},{0,0,0,1,1}};


int main()
{

    time_t t;
    srand((unsigned) time(&t));
/*
    Lista *li = cria_lista();

    for(int i=0; i<ARRAYSIZE; i++)
        insere_lista_final(li, rand()%20+1);
    imprime_lista(li);
    mergeSort(li, 0, ARRAYSIZE);
    imprime_lista(li);
*/

/****************** so para testar ********************/
    int i,j;
    int x0 = 1;
    int y0 = 1;

    int **M;
    M = (int**)malloc(L*sizeof(int*));
    for(i=0; i<L; i++)
        M[i] = (int*)malloc(C*sizeof(int));

    for(i=0; i<L; i++){
        for(j=0; j<C; j++){
            //M[i][j] = rand()%2;
            M[i][j] = matrix[i][j];
        }
    }
    for(i=0; i<L; i++){
        for(j=0; j<C; j++){
            printf("%d ",M[i][j]);
        }
        printf("\n");
    }
    printf("\n");

/*******************************************************/

    Lista *li;

    li = floodFill(M,x0,y0,L,C); // PARAMETROS: matriz, x inicial, y inicial, numero de lin, numero de col

    imprime_lista(li);

/****************** so para testar ********************/

    printf("\n\n");
    for(i=0; i<L; i++){
        for(j=0; j<C; j++){
            printf("%d ",M[i][j]);
        }
        printf("\n");
    }

/*******************************************************/


    libera_lista(li);
    return 0;
}
