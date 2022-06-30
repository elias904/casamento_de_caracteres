#include <stdio.h>
#include <stdlib.h>
#include "../read.h"
#include "../BruteForce/Bruteforce.h"
#include "bmh.h"
#include "../write.h"

void BoyerMooreHorspool(Nota *Texto, Nota *Busca, int TTexto, int TBusca)
{
    char P[TTexto];

    for (int x = 0; x < TTexto; x++)
    {
        P[x] = '-';
    }
    int j, k = 0;

    // Vetor em que cada indice indica as distancias
    int d[12];

    int dBusca[TBusca - 2];
    int dTexto[TTexto - 2];

    int x = 0;

    
    for (x = 0; x < TBusca - 1; x++)
    {
        dBusca[x] = Distancia(Busca[x].N, Busca[x].modulo, Busca[x + 1].N, Busca[x + 1].modulo);
       
    }

    
    for (x = 0; x < TTexto - 1; x++)
    {
        dTexto[x] = Distancia(Texto[x].N, Texto[x].modulo, Texto[x + 1].N, Texto[x + 1].modulo);
        
    }
    

    for (int x = 0; x <= 12; x++)
    {
        // Todos recebem o valor do Tamanho da Busca(Padrao)
        d[x] = TBusca - 1;
    }
    

    for (int x = 0; x < TBusca - 2; x++)
    {
        // Valor = Tamanho - index - 1
        d[dBusca[x]] = TBusca - 2 - x ;
    } 


    // Indices do final da minha lista de distâncias(dTexto e dBusca)
    int ITexto = TTexto - 2; // dTexto
    int IBusca = TBusca - 2; // dBusca

    // t - para acessar o indice do texto
    // b - para acessar o indice do padrão(busca)
    int t = 0;
    int b = 0;

    int achou = 0;

    int encontrado = 0;

    //Indice para o vetor de posições
    int q = 0;

    // para poder ver quantas comparações deram sucesso consecutivamente
    int count = 0;
    while (t + b < ITexto)
    {
        // indice 'b' sempre começa do final do padrão(busca)
        b = IBusca;

        // count = 0, para cada iteração de t(novo inicio) ele possa me dizer se há match ou não
        count = 0;

        // define uma variavel para poder funcionar para procura de padrões com unicos elementos
        achou = 0;

        // while para poder comparar os elementos de padrão e texto
        // começamos do final de padrão e em texto, temos t(inicio) + b, para poder fazer a comparação correta

        while (dBusca[b] == dTexto[t + b])
        {
            
            b--;
            count++;
            achou = 1;

        }
        if (count == IBusca + 1 && achou == 1)
        {
            encontrado = 1;
            P[q] = t;
            q++;
            t += 1;
        }
        else
        {
            t += d[dTexto[b + t]];
        }
    }
    if(encontrado == 1)
    {
        printf("S ");
        char S = 'S';
        grava(S);
    }
    else
    {
        printf("N ");
        char N = 'N';
        grava(N);
    }
    //Sinaliza que consigo armazenar as posições dentro da string
    for (int r = 0;P[r] != '-'; r++)
    {
        printf("%d", P[r]);
        gravaN(P[r]);
    }
}
