#include "TAD_lista.h"

//Variável global que conta quantas células foram modificadas
int modificado;

Lista* floodFill(int **M, int x0, int y0, int xSize, int ySize, int* count);

void buscaRecursiva(int **M, int x0, int y0, int xSize, int ySize, int ref);