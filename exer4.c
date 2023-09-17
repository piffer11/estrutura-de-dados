#include <stdio.h>

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(int matriz[][3], int baixo, int alto, int coluna) {
    int pivo = matriz[alto][coluna];
    int i = (baixo - 1);

    for (int j = baixo; j <= alto - 1; j++) {
        if (matriz[j][coluna] < pivo) {
            i++;
            for (int k = 0; k < 3; k++) {
                trocar(&matriz[i][k], &matriz[j][k]);
            }
        }
    }

    for (int k = 0; k < 3; k++) {
        trocar(&matriz[i + 1][k], &matriz[alto][k]);
    }
    
    return (i + 1);
}

void quickSort(int matriz[][3], int baixo, int alto, int coluna) {
    if (baixo < alto) {
        int pi = particionar(matriz, baixo, alto, coluna);

        quickSort(matriz, baixo, pi - 1, coluna);
        quickSort(matriz, pi + 1, alto, coluna);
    }
}

void imprimirMatriz(int matriz[][3], int linhas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matriz[][3] = {
        {3, 1, 4},
        {1, 5, 9},
        {2, 6, 5},
        {3, 5, 8}
    };

    int linhas = sizeof(matriz) / sizeof(matriz[0]);
    int coluna = 0;

    printf("Matriz original:\n");
    imprimirMatriz(matriz, linhas);

    quickSort(matriz, 0, linhas - 1, coluna);

    printf("\nMatriz ordenada:\n");
    imprimirMatriz(matriz, linhas);

    return 0;
}
