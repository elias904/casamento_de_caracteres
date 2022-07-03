#include <stdio.h>
#include "read.h"

int main(int argc, char **argv)
{
    if(argv[1] == NULL || argv[2] == NULL)
    {
        printf("\nExecucao FALTANDO Argumento!!!\n");
    }
    ReadFile(argv[1],argv[2]);

    return 1;
}