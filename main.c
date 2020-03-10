#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mergesort.h"

#define ARRAYSIZE 10
int main()
{
    time_t t;
    srand((unsigned) time(&t));

    Lista *li = cria_lista();
    for(int i=0; i<ARRAYSIZE; i++)
        insere_lista_final(li, rand()%20+1);
    imprime_lista(li);
    mergeSort(li, 0, ARRAYSIZE);
    imprime_lista(li);

    libera_lista(li);
    return 0;
}
