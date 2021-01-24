#include "../matrix/matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

int main(void){

    m_type **A = MatrixInit(3, 3);
    m_type **B = MatrixInit(3, 3);
    m_type *b = (m_type *)malloc((4) * sizeof(m_type));

    b[0] = 1;
    b[1] = -2;
    b[2] = 28;
    b[3] = 8;

    A[1][0] = 1;
    A[1][1] = -3;
    A[1][2] = 2;

    A[2][0] = -2;
    A[2][1] = 8;
    A[2][2] = -1;

    A[3][0] = 4;
    A[3][1] = -6;
    A[3][2] = 5;

    B = GaussElim(A);
    MatrixPrint(B);
}