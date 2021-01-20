#include "matrix/matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

int main(void){
    srand(time(NULL));
    int row1, row2, column1, column2;
    bool status;

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
        m_type **M = MatrixMult(M1, M2);
        MatrixPrint(M1);
        MatrixPrint(M2);
        MatrixPrint(M);
        free(M1);
        free(M2);
        free(M);
        printf("FIM\n");
    } else printf("Multiplicacao impossivel. \n");
    return 0;
}