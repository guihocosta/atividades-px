#include <stdio.h>
#include <stdlib.h>

int* lineariza(int **mat, int n) {
    int tamanho = (n * (n + 1)) / 2;
    int* vetor = (int*)malloc(tamanho * sizeof(int));

    if (vetor == NULL)
        return NULL;

    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            vetor[k] = mat[i][j];
            k++;
        }
    }
    return vetor;
}

int main() {
    int n = 3;

    int **mat = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        mat[i] = (int*)malloc(n * sizeof(int));
    }

    int val = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j <= i) {
                mat[i][j] = val++;
            } else {
                mat[i][j] = 0;
            }
        }
    }

    int *vetor = lineariza(mat, n);

    if (vetor != NULL) {
        printf("Vetor linearizado: ");
        int tamanho = (n * (n + 1)) / 2;
        for (int i = 0; i < tamanho; i++) {
            printf("%d ", vetor[i]);
        }
        printf("\n");
        free(vetor);
    } else {
        printf("Erro na alocação de memória.\n");
    }

    for (int i = 0; i < n; i++) {
        free(mat[i]);
    }
    free(mat);

    return 0;
}
