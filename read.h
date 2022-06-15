#ifndef READ_H_
#define READ_H_

typedef struct
{
    char N; // O caracter em si ( Nota )

    int modulo; // Para diferenciar se ele é bemol(-1), sustenido(1) e normal(0)

    float frequencia;

} Nota;

void ReadFile(char *ArqNome);
Nota OrdenaTexto(int Ttexto, char *texto);
Nota OrdenaBusca(int Tbusca, char *busca);
void FuncaoTemporaria(int Ttexto, char *texto, int Tbusca, char *busca);
int AtribuiModulo(char M);

#endif