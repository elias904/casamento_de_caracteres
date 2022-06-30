#include <stdio.h>
#include <stdlib.h>
#include "write.h"

void grava(char K)
{
    FILE *Arq = NULL;
    Arq = fopen("tp3.out", "a");
    fprintf(Arq, "%c ", K);
    fclose(Arq);
}
void gravaN(char K)
{
    FILE *Arq = NULL;
    Arq = fopen("tp3.out", "a");
    fprintf(Arq, "%d ", K);
    fclose(Arq);
}