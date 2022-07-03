#ifndef BRUTEFORCE_H_
#define BRUTEFORCE_H_
#include "../read.h"

void ForcaBruta(Nota * Texto, Nota * Busca, int TamanhoBusca,int TTexto);

int Distancia(char C1, int M1, char C2, int M2);

int Procurar(Nota *Lista, char C, int modulo);

#endif