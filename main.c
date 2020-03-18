#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "prototipos.h"

#define ARRAYSIZE 10

//------CONTAGEM DE OPERACOES------//

int contagem = 0;
int contagemBusca = 0;
int contagemMerge = 0;

//---------------------------------//

int main()
{
    int** M;
    int L, C, x0, y0;

    contagem += 2; // chamada da funcao e atribuicao de valor para a variavel M
    M = receber_matriz(&L, &C, &x0, &y0); //PARAMETROS: numero de lin, numero de col, x inicial, y inicial

    // as operacoes relativas ao envio da contagem de operacoes do algoritmo
    // para um arquivo a parte nao serao consideradas na contagem
    salvar_matriz(M,L,C);

    contagem++;
    if(M == NULL){
        return 0;
    }

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

    contagem += 2;
    li = floodFill(M,x0,y0,L,C,&count); // PARAMETROS: matriz, x inicial, y inicial, numero de lin, numero de col,

    contagem++;
    contagemMerge = contagem;
    mergeSort(li, 0, count);
    contagemMerge = contagem - contagemMerge;

    contagem++;
    imprime_lista(li, count);

    contagem++;
    libera_lista(li);

    salvar_contagem(contagem, contagemBusca, contagemMerge);

    printf("\nOPERACOES:%d\n",contagem);
    printf("OPERACOES DA BUSCA RECURSIVA:%d\n",contagemBusca);
    printf("OPERACOES DO MERGE SORT:%d\n",contagemMerge);

    return 0;
}
