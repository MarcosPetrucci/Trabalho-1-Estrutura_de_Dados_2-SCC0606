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

Lista* cria_lista();                          //Cria (aloca) o inicio da  lista
int insere_lista(Lista* li, Tipo_Dado dt);    //Insere, no comeco da lista, um novo nodo
Nodo* consulta_lista_pos(Lista* li, int pos); //Consulta a posicao de um determinado nodo na lista
void imprime_lista(Lista* li, int count);     //Imprime os resultados obtidos, total e nodos modificados
void libera_lista(Lista* li);                 //Libera, adequadamente, os nodos dinamicamente alocados
Nodo* encontrar_ponteiro(struct elemento* no, int distancia);   //Retorna um ponteiro a apartir do ponteiro forncido
//------------------------------- MERGE SORT -------------------------------//

void mergeSort(int inicio, Nodo* pinicio, int fim); //Faz as sucessivas divisoes do merge sort
void mergeArray(int inicio, Nodo* pinicio, int meio, Nodo* pmeio, int fim); //Realiza a ordenacao nos pequenos arrays derivados


//----------------------------- BUSCA RECURSIVA -----------------------------//

Lista* floodFill(int **M, int x0, int y0, int xSize, int ySize, int* count); //Inicia o algoritmo de flood fill
void buscaRecursiva(int **M, int x0, int y0, int xSize, int ySize, int ref); //Realiza a busca recursiva na matriz dada

//------------------------- MANIPULAR FILES --------------------------------//
int** receber_matriz(int* L, int* C, int* x0, int* y0); // Recebe dados de entrada de um arquivo .txt
void salvar_matriz(int** M, int L, int C);  // Salva a matriz de entrada em um arquivo .txt
void salvar_contagem(int total, int busca, int merge); // Salva a contagem de operacoes em um arquivo .txt
void imprime_lista_file(Lista* li, int count);
