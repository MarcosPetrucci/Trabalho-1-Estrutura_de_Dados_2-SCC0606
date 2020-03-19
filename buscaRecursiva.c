#include <stdio.h>
#include <stdlib.h>

#include "prototipos.h"

// ------ Algoritmo recursivo de Flood Fill ------ //

const int dir[8][2] = {{-1,0},  // sobe
                       {-1,1},  // sobre-direita (diagonal)
                       {0,1},   // direita
                       {1,1},   // desce-direita
                       {1,0},   // desce
                       {1,-1},  // desce-esquerda
                       {0,-1},  // esquerda
                       {-1,-1}};// sobe-esquerda

Lista* li2;
int modificado;

Lista* floodFill(int** M, int x0, int y0, int xSize, int ySize, int* count){

    extern int contagem;

    contagem+=16; // atribuicao de valores a matriz dir[8][2]

    contagem+=3;
    li2 = cria_lista();
    modificado = 0;

    contagem++;
    buscaRecursiva(M,x0,y0,xSize,ySize,M[x0][y0]);

    contagem++;
    *count = modificado;

    return li2;
}

void buscaRecursiva(int** M, int x0, int y0, int xSize, int ySize, int ref){

    int i;
    extern int contagem;

    contagem+=2;
    if(x0 < 0 || y0 < 0)
        return;

    contagem+=2;
    if(x0 >= xSize || y0 >= ySize)
        return;

    contagem++;
    if(M[x0][y0] == ref){

        // troca do valor da posição já visitada da matriz para a recursão não entrar em loop:
        M[x0][y0] = !ref;
        modificado++;
        contagem+=3;

        Tipo_Dado pos;
        pos.x = x0;
        pos.y = y0;
        contagem+=2;

        insere_lista(li2,pos); contagem++;

        // chamada recursiva para cada uma das 8 posicoes vizinhas:

        contagem+=2; // inicializacao e ultima comparacao do for
        for(i = 0; i < 8; i++){
            contagem+=4;    // comparacao, incremento(+2) e chamada da funcao
            buscaRecursiva(M, x0+dir[i][0], y0+dir[i][1], xSize, ySize, ref);
        }
    }

    return;
}
