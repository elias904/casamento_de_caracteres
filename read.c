#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "read.h"
#include "BruteForce/Bruteforce.h"

void ReadFile(char *ArqNome)
{

    FILE *ArqP = NULL;

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
        printf("\n\nLinha[%d]", count);
        fgetc(ArqP);
        fgets(Linha_0, 100, ArqP);
        fgets(Linha_1, 100, ArqP);

        /* TEXTO = OrdenaTexto(um, Linha_0);
        BUSCA = OrdenaBusca(dois, Linha_1); */

        // Passado como parametro os textos, busca e o tamanho das bucas, bloco por bloco.

        FuncaoTemporaria(um, Linha_0, dois, Linha_1);
        count++;
    }

    fclose(ArqP);
    printf("\n");
}

// Insere o 'texto' dentro do tipo Nota
Nota OrdenaTexto(int Ttexto, char *texto)
{
    printf("\nTEXTO: \n");
    // Structs para poder armazenas as informações do
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
    return *NotasTexto;
}
// Insere a 'busca' dentro do tipo Nota
Nota OrdenaBusca(int Tbusca, char *busca)
{
    printf("\nBUSCA: \n");
    Nota *NotasBusca;
    int k = 0;
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
    return *NotasBusca;
}

void FuncaoTemporaria(int Ttexto, char *texto, int Tbusca, char *busca)
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
    ForcaBruta(NotasTexto, NotasBusca, Tbusca);
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

Nota AtribuiFrequencia(Nota *Lista)
{
    for (int k = 0; Lista[k].N != '\0'; k++)
    {
    }
}

float Frequencia(int Ascii)
{
    // Na perspectiva de que um sustenido ou bemol é a soma do Ascii do caractere + '#' ou + 'b'
    // Considerando A, A#, B, C, C#, D, D#, E, F, F#, G, G#
}
