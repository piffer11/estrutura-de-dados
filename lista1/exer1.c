#include <stdio.h>

struct Pessoa {
    char nome[50];
    int idade;
    float altura;
};
int main() {

    struct Pessoa pessoa1;

    printf("Digite o nome da pessoa: ");
    scanf("%s", pessoa1.nome);

    printf("Digite a idade da pessoa: ");
    scanf("%d", &pessoa1.idade);

    printf("Digite a altura da pessoa (em metros): ");
    scanf("%f", &pessoa1.altura);

    printf("\nInformacoes da Pessoa:\n");
    printf("Nome: %s\n", pessoa1.nome);
    printf("Idade: %d anos\n", pessoa1.idade);
    printf("Altura: %.2f metros\n", pessoa1.altura);

    return 0;
}
