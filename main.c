#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "mergesort.h"
#include "buscaRecursiva.h"

#define ARRAYSIZE 10

#define L 8
#define C 10

int matrix[L][C] = {{0,0,0,0,0,0,0,0,0,0},
                    {0,0,1,1,0,0,0,0,0,0},
                    {0,0,0,0,1,1,0,0,0,0},
                    {0,0,0,0,1,1,0,0,0,0},
                    {0,0,1,1,1,0,0,0,0,0},
                    {0,0,0,0,1,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,1,1,0,0,0,0,0,0}};


int main()
{
/*
    time_t t;
    srand((unsigned) time(&t));

    Lista *li = cria_lista();

    for(int i=0; i<ARRAYSIZE; i++) {
        Tipo_Dado no;
        no.x = rand()%20+1;
        no.y = rand()%20+1;
        insere_lista_final(li, no);
    }
    imprime_lista(li);
    mergeSort(li, 0, ARRAYSIZE);
    printf("\n\n");
    imprime_lista(li);
*/

/****************** so para testar ********************/
    int i,j;
    // POSICAO INICIAL
    int x0 = 1;
    int y0 = 2;

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
    int count;

    li = floodFill(M,x0,y0,L,C,&count); // PARAMETROS: matriz, x inicial, y inicial, numero de lin, numero de col,
                                        // contador de nos modificados

    printf("Numero de posicoes conectadas: %d\n",count);

    mergeSort(li, 0, count);
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
