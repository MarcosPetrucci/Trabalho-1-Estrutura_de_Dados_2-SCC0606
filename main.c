#include<stdio.h>
#include<stdlib.h>
#include"TAD_lista.h"

int main()
{
    Lista* li = cria_lista();

    libera_lista(li);
    return 0;
}
