#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "read.h"
#include "BruteForce/Bruteforce.h"
#include "BMH/bmh.h"
#include "write.h"

void ReadFile(char *ArqNome, char *K)
{
    FILE *ArqP = NULL;

    //Processo para recriar o arquivo a cada chamada da função
    FILE *cArq = NULL;

    cArq = fopen("tp3.out", "w");

    fclose(cArq);
    /////////////////////////////////////////////////////////

    ArqP = fopen(ArqNome, "r");

    int um, dois = 0;

    char Linha_0[100];

    char Linha_1[100];

    int count = 0;

    while (!feof(ArqP))
    {
        fscanf(ArqP, "%d %d", &um, &dois);
        if (um == 0 && dois == 0)
            break;
        //printf("\n\nLinha[%d]", count);
        printf("\n");
        grava('\n');
        fgetc(ArqP);
        fgets(Linha_0, 100, ArqP);
        fgets(Linha_1, 100, ArqP);

        // Passado como parametro os textos, busca e o tamanho das bucas, bloco por bloco.

        FuncAux(um, Linha_0, dois, Linha_1, K);
        count++;
    }

    fclose(ArqP);
    printf("\n");
}

void FuncAux(int Ttexto, char *texto, int Tbusca, char *busca, char *K)
{

    Nota *NotasTexto = (Nota *)malloc(Ttexto * sizeof(Nota));

    int k = 0;
    // Faz atribuição para dentro do meu struct sinalizando cada letra e seu modulo
    for (int i = 0; texto[i] != '\0'; i++)
    {
        if (isalpha(texto[i]) && texto[i] != 'b')
        {
            NotasTexto[k].N = texto[i];
            NotasTexto[k].modulo = 0;
            if (texto[i + 1] == '#' || texto[i + 1] == 'b')
            {
                NotasTexto[k].modulo = AtribuiModulo(texto[i + 1]);
            }
            k++;
        }
    }

    Nota *NotasBusca = (Nota *)malloc(Tbusca * sizeof(Nota));

    k = 0;
    // Faz atribuição para dentro do meu struct sinalizando cada letra e seu modulo
    for (int i = 0; busca[i] != '\0'; i++)
    {
        if (isalpha(busca[i]) && busca[i] != 'b')
        {
            NotasBusca[k].N = busca[i];
            NotasBusca[k].modulo = 0;
            if (busca[i + 1] == '#' || busca[i + 1] == 'b')
            {
                NotasBusca[k].modulo = AtribuiModulo(busca[i + 1]);
            }
            k++;
        }
    }

    //Chamada dos algoritmos
    if (K[0] == '1')
    {
        ForcaBruta(NotasTexto, NotasBusca, Tbusca, Ttexto);
    }
    else if (K[0] == '2')
    {
        BoyerMooreHorspool(NotasTexto, NotasBusca, Ttexto, Tbusca);
    }
}
// A partir do caractere atribuimos valor para o atributo do modulo da nota, sabendo se a nota
// tem bemol, sustenido ou normal
int AtribuiModulo(char M)
{
    if (M == '#')
    {
        return 1;
    }
    else if (M == 'b')
    {
        return -1;
    }
}
