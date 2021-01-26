#include "../matrix/matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#define NUM_SIZE 37
#define printArray 0
#define rand_init false

int main(void){

    FILE *fp, *fp2;
    srand(time(NULL));
    int size = 0, aux = 0;

    m_type **A;
    m_type *b;
    m_type *x;

    if (rand_init){
        printf("Digite o tamanho dos sistemas lineares (Ax = b): ");
        scanf("%d", &size);

        A = MatrixInit(4, 4);
        b = (m_type *)malloc((4) * sizeof(m_type));
        x = (m_type *)malloc((4) * sizeof(m_type));

        for (int i = 0; i < size; i++){
            aux = (rand() % NUM_SIZE);
            b[i] = (m_type)aux;
            // printf("b = %f\naux = %d \n", b[i], aux);
        }
        A = RandomInit(A, "A.txt");
    }
    else {
        A = MatrixInit(4, 4);
        b = (m_type *)malloc((4) * sizeof(m_type));
        x = (m_type *)malloc((4) * sizeof(m_type));
        size = 4;

        A[1][0] = 1;
        A[1][1] = 2;
        A[1][2] = 1;
        A[1][3] = -1;

        A[2][0] = 1.5;
        A[2][1] = 1;
        A[2][2] = 2;
        A[2][3] = 2;

        A[3][0] = 4;
        A[3][1] = 4;
        A[3][2] = 3;
        A[3][3] = 4;

        A[4][0] = 0.4;
        A[4][1] = 0;
        A[4][2] = 0.2;
        A[4][3] = 1;

        b[0] = 5;
        b[1] = 8;
        b[2] = 22;
        b[3] = 3;
        SaveMatrix(A, "A.txt");

    }

    fp = fopen("b.txt", "w");
    fprintf(fp, "size: %d \n", size);
    for(int i = 0; i < size; i++){
            fprintf(fp, "%.15f ", b[i]);
    }

    GaussElim(A, b);

    fp2 = fopen("b2.txt", "w");
    fprintf(fp2, "size: %d \n", size);
    for(int i = 0; i < size; i++){
            fprintf(fp2, "%.15f ", b[i]);
    }
    // MatrixPrint(A);
    x = LSDiagSup(A, b);

    if (printArray){
        for (int i = 0; i < size; i++) {
            printf("x[%d] = %f \n", i, x[i]);
        }
    }

    fclose(fp);
    free(A);
    free(x);
    free(b);
}