#include <stdio.h>
#include <string.h>

#include "prototipos.h"

int** receber_matriz(int* L, int* C, int* x0, int* y0)
{
    //Ler o nome do arquivo
    char nome[50];

    printf("Digite o nome do arquivo: ");
    scanf("%s", nome);

    strcat(nome, ".txt"); //Concatenando as strings

    //Manipulacao de arquivos

    FILE* arquivo;

    arquivo = fopen(nome, "r");

    if(arquivo == NULL)
    {
        printf("\nERRO NA ABERTURA DO ARQUIVO\n");
        return 0;
    }

    //Leitura das dimensoes da matriz
    int linhas = 0;
    int colunas = 0;

    fscanf(arquivo, "%d %d", &linhas, &colunas);

    //Criacao da matriz
    int i = 0;
    int j = 0;
    int** matriz;

    matriz = (int**)malloc(linhas*sizeof(int*));

    for(i = 0; i < linhas; i++)
        matriz[i] = (int*)malloc(colunas*sizeof(int));

    //Preenchimento da matriz
    for(i = 0; i < linhas; i++)
        for(j = 0; j < colunas; j++)
        {
            fscanf(arquivo, "%d", &matriz[i][j]);
        }

    //Lendo x0 e y0
    int xi;
    int yi;

    fscanf(arquivo, "%d %d", &xi, &yi);

    fclose(arquivo);

    //Atribuindo valores para L, C, x0 e y0 da main
    *L = linhas;
    *C = colunas;
    *x0 = xi;
    *y0 = yi;

    return matriz;
}
