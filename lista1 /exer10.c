#include <stdio.h>

struct Moeda {
    float dolares;
    float euros;
};

const float TAXA_DE_CAMBIO = 0.85;

float converterDolaresParaEuros(float valorEmDolares) {
    return valorEmDolares * TAXA_DE_CAMBIO;
}

float converterEurosParaDolares(float valorEmEuros) {
    return valorEmEuros / TAXA_DE_CAMBIO;
}

int main() {
    struct Moeda moeda;

    printf("Digite o valor em dolares: ");
    scanf("%f", &moeda.dolares);

    printf("Digite o valor em euros: ");
    scanf("%f", &moeda.euros);

    printf("\nEscolha uma opcao:\n");
    printf("1. Converter de dolares para euros\n");
    printf("2. Converter de euros para dolares\n");
    int escolha;
    scanf("%d", &escolha);

    switch (escolha) {
        case 1:
            moeda.euros = converterDolaresParaEuros(moeda.dolares);
            printf("Valor em euros: %.2f\n", moeda.euros);
            break;
        case 2:
            moeda.dolares = converterEurosParaDolares(moeda.euros);
            printf("Valor em dolares: %.2f\n", moeda.dolares);
            break;
        default:
            printf("Opcao invalida.\n");
            break;
    }

    return 0;
}
