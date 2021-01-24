#include "../matrix/matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

int main(void){

    m_type **A = MatrixInit(4, 4);
    m_type **B = MatrixInit(4, 4);
    m_type *b = (m_type *)malloc((4) * sizeof(m_type));

    b[0] = 1;
    b[1] = -2;
    b[2] = 28;
    b[3] = 8;

    A[1][0] = 5;
    A[1][1] = -2;
    A[1][2] = 6;
    A[1][3] = 1;

    A[2][0] = 3;
    A[2][1] = 3;
    A[2][2] = 7;
    A[2][3] = -4;

    A[3][0] = 9;
    A[3][1] = 12;
    A[3][2] = 4;
    A[3][3] = 19;

    A[4][0] = -54;
    A[4][1] = -7;
    A[4][2] = 55;
    A[4][3] = 12;

    B = GaussElim(A, b);
    MatrixPrint(B);
}