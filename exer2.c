#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                trocar(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int particionar(int arr[], int baixo, int alto) {
    int pivo = arr[alto];
    int i = (baixo - 1);
    for (int j = baixo; j <= alto - 1; j++) {
        if (arr[j] < pivo) {
            i++;
            trocar(&arr[i], &arr[j]);
        }
    }
    trocar(&arr[i + 1], &arr[alto]);
    return (i + 1);
}

void quickSort(int arr[], int baixo, int alto) {
    if (baixo < alto) {
        int pi = particionar(arr, baixo, alto);
        quickSort(arr, baixo, pi - 1);
        quickSort(arr, pi + 1, alto);
    }
}

void merge(int arr[], int baixo, int meio, int alto) {
    int i, j, k;
    int n1 = meio - baixo + 1;
    int n2 = alto - meio;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++) {
        L[i] = arr[baixo + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[meio + 1 + j];
    }

    i = 0;
    j = 0;
    k = baixo;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(int arr[], int baixo, int alto) {
    if (baixo < alto) {
        int meio = baixo + (alto - baixo) / 2;

        mergeSort(arr, baixo, meio);
        mergeSort(arr, meio + 1, alto);

        merge(arr, baixo, meio, alto);
    }
}

int main() {
    srand(time(NULL));

    int tamanhos[] = {1000, 5000, 10000, 20000, 30000};

    for (int i = 0; i< sizeof(tamanhos) / sizeof(tamanhos[0]); i++) {
        int n = tamanhos[i];
        int *arrBubble = (int *)malloc(n * sizeof(int));
        int *arrQuick = (int *)malloc(n * sizeof(int));
        int *arrMerge = (int *)malloc(n * sizeof(int));

        for (int j = 0; j < n; j++) {
            int num = rand() % 100000;
            arrBubble[j] = num;
            arrQuick[j] = num;
            arrMerge[j] = num;
        }

        clock_t inicio = clock();
        bubbleSort(arrBubble, n);
        clock_t fim = clock();
        double tempoBubble = (double)(fim - inicio) / CLOCKS_PER_SEC;

        inicio = clock();
        quickSort(arrQuick, 0, n - 1);
        fim = clock();
        double tempoQuick = (double)(fim - inicio) / CLOCKS_PER_SEC;

        inicio = clock();
        mergeSort(arrMerge, 0, n - 1);
        fim = clock();
        double tempoMerge = (double)(fim - inicio) / CLOCKS_PER_SEC;

        printf("Tamanho do array: %d\n", n);
        printf("Tempo Bubble Sort: %lf segundos\n", tempoBubble);
        printf("Tempo QuickSort: %lf segundos\n", tempoQuick);
        printf("Tempo MergeSort: %lf segundos\n", tempoMerge);

        free(arrBubble);
        free(arrQuick);
        free(arrMerge);
    }

    return 0;
}
