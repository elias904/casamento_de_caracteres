#include <stdio.h>
#include "read.h"

int main(int argc, char **argv)
{
    if(argv[1] == NULL)
    {
        printf("\nExecucao sem Argumento, seu animal!!!\n");
    }
    ReadFile(argv[1]);

    return 1;
}