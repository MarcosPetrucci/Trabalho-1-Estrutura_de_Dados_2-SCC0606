#include <stdlib.h>
#include <stdio.h>
#include <time.h>


//------------------------ LISTA DINAMICA ENCADEADA DUPLA ------------------------//

#define FALSO      0
#define VERDADEIRO 1

#define OK         1
#define ERRO       0

typedef struct{
    int x;
    int y;
}Tipo_Dado;

//Definicao do tipo lista
struct elemento{

    Tipo_Dado dado;
    struct elemento *ant;
    struct elemento *prox;
};

typedef struct elemento Nodo;

typedef struct elemento* Lista;

Lista* cria_lista();                          //Cria (aloca) o início da  lista
int insere_lista(Lista* li, Tipo_Dado dt);    //Insere, no começo da lista, um novo nodo
Nodo* consulta_lista_pos(Lista* li, int pos); //Consulta a posição de um determinado nodo na lista
void imprime_lista(Lista* li, int count);     //Imprime os resultados obtidos, total e nodos modificados
void libera_lista(Lista* li);                 //Libera, adequadamente, os nodos dinâmicamente alocados
//------------------------------- MERGE SORT -------------------------------//

void mergeSort(Lista* vetor, int inicio, int fim); //Faz as sucessivas divisões do merge sort
void mergeArray(Lista* vetor, int inicio, int meio, int fim); //Realiza a ordenação nos pequenos arrays derivados


//----------------------------- BUSCA RECURSIVA -----------------------------//

Lista* floodFill(int **M, int x0, int y0, int xSize, int ySize, int* count); //Inicia o algoritmo de flood fill
void buscaRecursiva(int **M, int x0, int y0, int xSize, int ySize, int ref); //Realiza a busca recursiva na matriz dada

//------------------------- MANIPULAR FILES --------------------------------//
int** receber_matriz(int* L, int* C, int* x0, int* y0);
void salvar_matriz(int** M, int L, int C);
void salvar_contagem(int total, int busca, int merge);
