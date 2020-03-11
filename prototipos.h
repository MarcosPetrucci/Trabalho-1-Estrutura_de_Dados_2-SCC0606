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
    struct elemento *ant;
    Tipo_Dado dado;
    struct elemento *prox;
};

typedef struct elemento Elem;

typedef struct elemento* Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
Elem* consulta_lista_pos(Lista* li, int pos);
int insere_lista_final(Lista* li, Tipo_Dado dt);
int insere_lista(Lista* li, Tipo_Dado dt);
int tamanho_lista(Lista* li);
void imprime_lista(Lista* li);
int remove_lista(Lista* li);


//------------------------------- MERGE SORT -------------------------------//

void mergeSort(Lista* vetor, int inicio, int fim);
void mergeArray(Lista* vetor, int inicio, int meio, int fim);


//----------------------------- BUSCA RECURSIVA -----------------------------//

Lista* floodFill(int **M, int x0, int y0, int xSize, int ySize, int* count);
void buscaRecursiva(int **M, int x0, int y0, int xSize, int ySize, int ref);

