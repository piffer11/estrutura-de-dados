#include <stdio.h>

int searchInMatrix(int matrix[][100], int rows, int cols, int target, int *row, int *col) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == target) {
                *row = i;
                *col = j;
                return 1;
            }
        }
    }
    return 0; 
}

int main() {
    int rows, cols, target;

    printf("Digite o numero de linhas da matriz: ");
    scanf("%d", &rows);

    printf("Digite o numero de colunas da matriz: ");
    scanf("%d", &cols);

    if (rows <= 0 || cols <= 0 || rows > 100 || cols > 100) {
        printf("Tamanho da matriz fora do intervalo valido.\n");
        return 1;
    }

    int matrix[100][100];

    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Digite o valor que deseja encontrar na matriz: ");
    scanf("%d", &target);

    int row, col;
    int found = searchInMatrix(matrix, rows, cols, target, &row, &col);

    if (found) {
        printf("Valor encontrado na posicao (%d, %d).\n", row, col);
    } else {
        printf("Valor nao encontrado na matriz.\n");
    }

    return 0;
}
