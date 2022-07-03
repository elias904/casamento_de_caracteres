#ifndef READ_H_
#define READ_H_



//struct para o armazenamento das notas
typedef struct
{
    char N; // O caracter em si ( Nota )

    int modulo; // Para diferenciar se ele é bemol(-1), sustenido(1) e normal(0)

} Nota;

void ReadFile(char *ArqNome,char *K);

void FuncAux(int Ttexto, char *texto, int Tbusca, char *busca,char *K);

int AtribuiModulo(char M);

#endif