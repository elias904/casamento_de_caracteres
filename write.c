#include <stdio.h>
#include <stdlib.h>
#include "write.h"

//Se for uma letra 
void grava(char K)
{
    FILE *Arq = NULL;
    Arq = fopen("tp3.out", "a");
    fprintf(Arq, "%c ", K);
    fclose(Arq);
}
//Se for um numero
void gravaN(char K)
{
    FILE *Arq = NULL;
    Arq = fopen("tp3.out", "a");
    fprintf(Arq, "%d ", K);
    fclose(Arq);
}