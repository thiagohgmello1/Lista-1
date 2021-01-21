#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

int main(void){
    srand(time(NULL));
    int row1 = 0, row2 = 0, column1 = 0, column2 = 0;
    bool status;
    double norm = 0;

    printf("Digite o numero de linhas da primeira matriz (matriz A em A*B): ");
    scanf("%d", &row1);
    printf("Digite o numero de colunas da primeira matriz (matriz A em A*B): ");
    scanf("%d", &column1);
    printf("Digite o numero de linhas da segunda matriz (matriz B em A*B): ");
    scanf("%d", &row2);
    printf("Digite o numero de colunas da segunda matriz (matriz B em A*B): ");
    scanf("%d", &column2);
    
    status = EqualStatus(column1, row2);
    if (status == true){
        printf("INICIO\n");
        m_type **M1 = MatrixInit(row1, column1);
        m_type **M2 = MatrixInit(row2, column2);
        M1 = RandomInit(M1);
        M2 = RandomInit(M2);
        m_type **M = MatrixMult(M1, M2);
        SaveMatrix(M1, "Matrizes.txt");
        SaveMatrix(M2, "Matrizes.txt");
        SaveMatrix(M, "Matrizes.txt");
        MatrixPrint(M1);
        MatrixPrint(M2);
        MatrixPrint(M);
        norm = FrobeniusNorm(M1);
        free(M1);
        free(M2);
        free(M);
        printf("Norma de Frobenius: %.15lf \n", norm);
        printf("FIM\n");
    } else printf("Multiplicacao impossivel. \n");
    return 0;
}