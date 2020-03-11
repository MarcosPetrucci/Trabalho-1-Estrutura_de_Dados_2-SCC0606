//Arquivo LDED.h - Lista Dinamica Encadeada Dupla

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

