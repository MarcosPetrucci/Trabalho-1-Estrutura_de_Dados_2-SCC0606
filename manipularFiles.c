#include <stdio.h>
#include <string.h>

#include "prototipos.h"

int** receber_matriz(int* L, int* C, int* x0, int* y0)
{
    //Ler o nome do arquivo
    char nome[50];

    extern int contagem;

    contagem += 2;
    printf("Digite o nome do arquivo (sem extensao): ");
    scanf("%s", nome);

    contagem++;
    strcat(nome, ".txt"); //Concatenando as strings

    //Manipulacao de arquivos

    FILE* arquivo;

    contagem += 2;
    arquivo = fopen(nome, "r");

    contagem++;
    if(arquivo == NULL)
    {
        printf("\nERRO NA ABERTURA DO ARQUIVO\n");
        return NULL;
    }

    //Leitura das dimensoes da matriz
    contagem+=3;
    int linhas = 0;
    int colunas = 0;
    fscanf(arquivo, "%d %d", &linhas, &colunas);

    //Criacao da matriz
    int i = 0;
    int j = 0;
    int** matriz;

    contagem+=2;
    matriz = (int**)malloc(linhas*sizeof(int*));

    contagem+=2; // inicializacao e ultima comparacao do for
    for(i = 0; i < linhas; i++){
        contagem+=5; // comparacao, incremento(+2), atribuicao e chamada da funcao malloc
        matriz[i] = (int*)malloc(colunas*sizeof(int));
    }

    //Preenchimento da matriz
    contagem+=2;
    for(i = 0; i < linhas; i++){
        contagem+=5;
        for(j = 0; j < colunas; j++)
        {
            contagem+=4;
            fscanf(arquivo, "%d", &matriz[i][j]);
        }
    }

    //Lendo x0 e y0
    int xi;
    int yi;

    fscanf(arquivo, "%d %d", &xi, &yi); contagem++;

    fclose(arquivo); contagem++;

    //Atribuindo valores para L, C, x0 e y0 da main
    contagem+=4;
    *L = linhas;
    *C = colunas;
    *x0 = xi;
    *y0 = yi;

    return matriz;
}

void salvar_matriz(int** M, int L, int C){

    FILE *output;
    int i,j;

    output =fopen("contagem_de_operacoes.txt","a+");

    if(output == NULL){
        printf("\nERRO NA ABERTURA DO ARQUIVO\n");
        return;
    }

    fprintf(output,"\nContagem das operacoes para a seguinte matriz de entrada:\n");
    for(i=0; i<L; i++){
        for(j=0; j<C; j++){
            fprintf(output,"%d ",M[i][j]);
        }
        fprintf(output,"\n");
    }

    fclose(output);

}

void salvar_contagem(int total, int busca, int merge){
    
    FILE *output;

    output =fopen("contagem_de_operacoes.txt","a+");

    if(output == NULL){
        printf("\nERRO NA ABERTURA DO ARQUIVO\n");
        return;
    }

    fprintf(output,"Total de operacoes: %d\n",total);
    fprintf(output,"Operacoes devido a busca recursiva: %d\n",busca);
    fprintf(output,"Operacoes devido ao merge sort: %d\n",merge);

    fclose(output);
}