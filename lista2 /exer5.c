#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, chave, j;
    for (i = 1; i < n; i++) {
        chave = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = chave;
    }
}

void printMatrix(int matrix[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;

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

    for (int i = 0; i < rows; i++) {
        insertionSort(matrix[i], cols);
    }

    printf("Matriz ordenada em ordem crescente por linha:\n");
    printMatrix(matrix, rows, cols);

    return 0;
}
