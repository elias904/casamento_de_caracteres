#include "Bruteforce.h"
#include <stdio.h>
#include "../read.h"

void ForcaBruta(Nota *Texto, Nota *Busca, int TamanhoBusca)
{
    int c = 0;
    int e = 0;

    for (int t = 0; Texto[t + TamanhoBusca].N != '\0'; t++)
    {
        int count = 0;
        for (int p = 0; Busca[p].N != '\0'; p++)
        {

            c = Distancia(Texto[t + p].N, Texto[t + p].modulo, Texto[t + p + 1].N, Texto[t + p + 1].modulo);
            e = Distancia(Busca[p].N, Busca[p].modulo, Busca[p + 1].N, Busca[p + 1].modulo);

            if (c == e)
            {
                count++;
                if (count == TamanhoBusca - 1)
                    printf("\nEncontrei: %d\n", t);
            }
        }
    }
}

// C1 - Caracter1, C2 - Caracter2, M1 - Modulo de 1, M2 - Modulo de 2
//Busca a distancia entre C1 e C2
int Distancia(char C1, int M1, char C2, int M2)
{
    // Lista considerando sustenidos
    Nota ListaSus[12];

    ListaSus[0].N = 'A';
    ListaSus[0].modulo = 0;

    ListaSus[1].N = 'A';
    ListaSus[1].modulo = 1; // Sustenido

    ListaSus[2].N = 'B';
    ListaSus[2].modulo = 0;

    ListaSus[3].N = 'C';
    ListaSus[3].modulo = 0;

    ListaSus[4].N = 'C';
    ListaSus[4].modulo = 1; // Sustenido

    ListaSus[5].N = 'D';
    ListaSus[5].modulo = 0;

    ListaSus[6].N = 'D';
    ListaSus[6].modulo = 1; // Sustenido

    ListaSus[7].N = 'E';
    ListaSus[7].modulo = 0;

    ListaSus[8].N = 'F';
    ListaSus[8].modulo = 0;

    ListaSus[9].N = 'F';
    ListaSus[9].modulo = 1; // Sustenido

    ListaSus[10].N = 'G';
    ListaSus[10].modulo = 0;

    ListaSus[11].N = 'G';
    ListaSus[11].modulo = 1; // Sustenido

    //Lista de Notas considerando os bemois
    Nota ListaBem[12];

    ListaBem[0].N = 'A';
    ListaBem[0].modulo = 0;

    ListaBem[1].N = 'B';
    ListaBem[1].modulo = -1; // Bemol

    ListaBem[2].N = 'B';
    ListaBem[2].modulo = 0;

    ListaBem[3].N = 'C';
    ListaBem[3].modulo = 0;

    ListaBem[4].N = 'D';
    ListaBem[4].modulo = -1; // Bemol

    ListaBem[5].N = 'D';
    ListaSus[5].modulo = 0;

    ListaBem[6].N = 'E';
    ListaBem[6].modulo = -1; // Bemol

    ListaBem[7].N = 'E';
    ListaBem[7].modulo = 0;

    ListaBem[8].N = 'F';
    ListaBem[8].modulo = 0;

    ListaBem[9].N = 'G';
    ListaBem[9].modulo = -1; // Bemol

    ListaBem[10].N = 'G';
    ListaBem[10].modulo = 0;

    ListaBem[11].N = 'A';
    ListaBem[11].modulo = -1; // Bemol

    int R1,R2 = 0;

    if(M1 == -1)
    {
        R1 = Procurar(ListaBem,C1,M1);
    }
    else
    {
        R1 = Procurar(ListaSus,C1,M1);
    }
    if(M2 == -1)
    {
        R2 = Procurar(ListaBem,C2,M2);
        
    }
    else
    {
        R2 = Procurar(ListaSus,C2,M2);
    }

    // Retornamos a Distancia de R1 para R2

    if (R1 > R2)
    {
        // Ou seja, R1 está depois de R2
        int Temp = 12 - (R1 - R2);

        return Temp;
    }
    else if (R1 < R2)
    {
        // Ou seja, R1 está antes de R2
        int Temp = R2 - R1;

        return Temp;
    }
    else
    {
        // Eles estão na mesma posição e consequentemente a distância entre eles é zero
        return 0;
    }
}

int Procurar(Nota *Lista, char C, int modulo)
{
    int i = 0;
    for (i = 0; Lista[i].N != '\0'; i++)
    {
        if (Lista[i].N == C && Lista[i].modulo == modulo)
        {
            break;
        }
    }
    return i;
}