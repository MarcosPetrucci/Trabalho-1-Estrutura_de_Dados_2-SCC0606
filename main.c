#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "prototipos.h"

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

    contagem++;
    salvar_matriz(M,L,C);   // envia para o arquivo saida_dados.txt a matriz inicial

    contagem++;
    if(M == NULL){
        return 0;
    }

/************************************** TESTE **********************************************/
    // int i,j;

    // printf("L = %d\n\nC = %d\n\nx0 = %d\n\ny0 = %d\n\n", L, C, x0, y0); //Imprime L, C, x0 e y0

    // for(i=0; i<L; i++){
    //     for(j=0; j<C; j++){
    //         printf("%d ",M[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");

/*******************************************************************************************/

    Lista *li;
    int count;  //Contador de nodos modificados

    contagem += 2;
    contagemBusca = contagem;
    li = floodFill(M,x0,y0,L,C,&count); // PARAMETROS: matriz, x inicial, y inicial, numero de lin, numero de col, numero de elementos modificados
    contagemBusca = contagem - contagemBusca;

    contagem++;
    contagemMerge = contagem;
    mergeSort(0, (*li), count);
    contagemMerge = contagem - contagemMerge;

    contagem++;
    imprime_lista(li, count);   // retorna, em tela, o numero de posicoes do mesmo
                                // conectadas, a partir da posicao inicial, seguido de suas
                                // coordenadas

    contagem++;
    imprime_lista_file(li, count);  // envia a saida do programa para o arquivo saida_dados.txt

    contagem++;
    libera_lista(li);

    contagem++;
    salvar_contagem(contagem, contagemBusca, contagemMerge); // envia a contagem de operacoes para
                                                             // o arquivo saida_dados.txt

    // printf("\nOPERACOES:%d\n",contagem);
    // printf("OPERACOES DA BUSCA RECURSIVA:%d\n",contagemBusca);
    // printf("OPERACOES DO MERGE SORT:%d\n",contagemMerge);

    return 0;
}
