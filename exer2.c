#include <stdio.h>

struct Tipo {
    int inteiro;
    float pontoFlutuante;
    char letra;
};

int main() {
    struct Tipo meuTipo;
    meuTipo.inteiro = 42;
    meuTipo.pontoFlutuante = 3.14;
    meuTipo.letra = 'A';

    // Imprimindo os valores
    printf("Valor inteiro: %d\n", meuTipo.inteiro);
    printf("Valor de ponto flutuante: %.2f\n", meuTipo.pontoFlutuante);
    printf("Letra: %c\n", meuTipo.letra);

    return 0;
}
