#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "prototipos.h"

#define ARRAYSIZE 10

int main()
{
    int** M;
    int L, C, x0, y0;

    M = receber_matriz(&L, &C, &x0, &y0); //PARAMETROS: numero de lin, numero de col, x inicial, y inicial

/***************** so para testar *********************************************************/
    int i,j;

    printf("L = %d\n\nC = %d\n\nx0 = %d\n\ny0 = %d\n\n", L, C, x0, y0); //Imprime L, C, x0 e y0

    for(i=0; i<L; i++){
        for(j=0; j<C; j++){
            printf("%d ",M[i][j]);
        }
        printf("\n");
    }
    printf("\n");

/*******************************************************************************************/

    Lista *li;
    int count;  //Contador de nodos modificados

    li = floodFill(M,x0,y0,L,C,&count); // PARAMETROS: matriz, x inicial, y inicial, numero de lin, numero de col,

    mergeSort(li, 0, count);
    imprime_lista(li, count);

    libera_lista(li);

    return 0;
}
