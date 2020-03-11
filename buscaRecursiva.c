#include <stdio.h>
#include <stdlib.h>

//#include "TAD_lista.h"
#include "buscaRecursiva.h"

const int dir[8][2] = {{-1,0},  // sobe
                       {-1,1},  // sobre-direita (diagonal)
                       {0,1},   // direita
                       {1,1},   // desce-direita
                       {1,0},   // desce
                       {1,-1},  // desce-esquerda
                       {0,-1},  // esquerda
                       {-1,-1}};// sobe-esquerda

Lista* li;
int modificado;

Lista* floodFill(int** M, int x0, int y0, int xSize, int ySize, int* count){

    li = cria_lista();
    modificado = 0;

    buscaRecursiva(M,x0,y0,xSize,ySize,M[x0][y0]);

    *count = modificado;

    return li;
}

void buscaRecursiva(int** M, int x0, int y0, int xSize, int ySize, int ref){
    
    int i;

    if(x0 < 0 || y0 < 0){
        return;
    }
    if(x0 >= xSize || y0 >= ySize){
        return;
    }

    if(M[x0][y0] == ref){
        
        // troca do valor da posição já visitada da matriz para a recursão não entrar em loop:
        M[x0][y0] = !ref;
        modificado++;

        Tipo_Dado pos;
        pos.x = x0;
        pos.y = y0;

        insere_lista(li,pos);

        // chamada recursiva para cada uma das 8 posicoes vizinhas:
        for(i=0; i<8; i++){ 
            buscaRecursiva(M, x0+dir[i][0], y0+dir[i][1], xSize, ySize, ref);
        }
    }

    return;
}