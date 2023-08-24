#include <stdio.h>
#include <math.h>

struct Ponto {
    double x;
    double y;
};

double calcularDistancia(struct Ponto p1, struct Ponto p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

double calcularInclinacao(struct Ponto p1, struct Ponto p2) {
    if (p2.x - p1.x == 0) {
        return INFINITY; // Reta vertical
    } else {
        return (p2.y - p1.y) / (p2.x - p1.x);
    }
}

int main() {
    struct Ponto ponto1 = {1.0, 2.0};
    struct Ponto ponto2 = {4.0, 6.0};

    printf("Ponto 1: (%.2f, %.2f)\n", ponto1.x, ponto1.y);
    printf("Ponto 2: (%.2f, %.2f)\n", ponto2.x, ponto2.y);

    double distancia = calcularDistancia(ponto1, ponto2);
    printf("Distancia entre os pontos: %.2f\n", distancia);

    double inclinacao = calcularInclinacao(ponto1, ponto2);
    if (isinf(inclinacao)) {
        printf("Inclinacao: Vertical\n");
    } else {
        printf("Inclinacao: %.2f\n", inclinacao);
    }

    return 0;
}
