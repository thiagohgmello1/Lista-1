#include "../matrix/matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define NUM_SIZE 37
#define printArray 0

int main(void){

    srand(time(NULL));
    FILE *fp1, *fp2;
    int size = 0, aux = 0;

    printf("Digite o tamanho dos sistemas lineares (Ax = b): ");
    scanf("%d", &size);

    m_type **A1 = MatrixInit(size, size);
    m_type **B1 = MatrixInit(size, size);
    m_type *b1 = (m_type *)malloc((size) * sizeof(m_type));
    m_type *x1 = (m_type *)malloc((size) * sizeof(m_type));

    m_type **A2 = MatrixInit(size, size);
    m_type **B2 = MatrixInit(size, size);
    m_type *b2 = (m_type *)malloc((size) * sizeof(m_type));
    m_type *x2 = (m_type *)malloc((size) * sizeof(m_type));

    for (int i = 0; i < size; i++){
        aux = (rand() % NUM_SIZE);
        b1[i] = aux;

        aux = (rand() % NUM_SIZE);
        b2[i] = aux;
    }

    for (int i = 1; i < size + 1; i++){
        for (int j = i - 1; j <= size; j++){
            aux = (rand() % NUM_SIZE);
            B1[i][j] = aux;
            A1[i][j] = log10(pow(M_PI, aux));
        }
    }
    
    for (int i = 1; i < size + 1; i++){
        for (int j = 0; j <= i - 1; j++){
            aux = (rand() % NUM_SIZE);
            B2[i][j] = aux;
            A2[i][j] = log10(pow(M_PI, aux));
            // A2[i][j] = aux;
        }
    }

    SaveMatrix(A1, "superior.txt");
    SaveMatrix(A2, "inferior.txt");

    x1 = LSDiagSup(A1, b1);
    x2 = LSDiagInf(A2, b2);

    if (printArray){
        for (int i = 0; i < size; i++) {
            printf("x1[%d] = %f \n", i, x1[i]);
        }
    }

    printf("Norma euclidiana do SL superior: %.16lf \n", EuclidianNorm(x1, size));
    printf("Norma euclidiana do SL inferior: %.16lf \n", EuclidianNorm(x2, size));

    fp1 = fopen("b1.txt", "w");
    fp2 = fopen("b2.txt", "w");

    fprintf(fp1, "size: %d \n", size);
    fprintf(fp2, "size: %d \n", size);
    for(int i = 0; i < size; i++){
            fprintf(fp1, "%.15f ", b1[i]);
            fprintf(fp2, "%.15f ", b2[i]);
    }

    fclose(fp1);
    fclose(fp2);

    free(A1);
    free(A2);
    free(B1);
    free(B2);
    free(x1);
    free(x2);
    free(b1);
    free(b2);

    return 0;
}