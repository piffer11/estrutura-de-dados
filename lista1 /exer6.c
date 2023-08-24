#include <stdio.h>
#include <string.h>

struct Estudante {
    char nome[50];
    int matricula;
    float notas[3]; 
};

float calcularMedia(struct Estudante aluno) {
    float soma = 0.0;
    for (int i = 0; i < 3; i++) {
        soma += aluno.notas[i];
    }
    return soma / 3;
}

int estaAprovado(struct Estudante aluno) {
    float media = calcularMedia(aluno);
    return (media >= 7.0);
}

int main() {
    struct Estudante estudante1;

    strcpy(estudante1.nome, "Joao");
    estudante1.matricula = 12345;
    estudante1.notas[0] = 8.5;
    estudante1.notas[1] = 7.0;
    estudante1.notas[2] = 6.5;

    float media = calcularMedia(estudante1);
    printf("Media das notas de %s: %.2f\n", estudante1.nome, media);

    if (estaAprovado(estudante1)) {
        printf("%s esta aprovado!\n", estudante1.nome);
    } else {
        printf("%s nao esta aprovado.\n", estudante1.nome);
    }

    return 0;
}
