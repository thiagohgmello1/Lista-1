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
    m_type *c = (m_type *)malloc((4) * sizeof(m_type));
    m_type *x = (m_type *)malloc((4) * sizeof(m_type));
    m_type *x2 = (m_type *)malloc((4) * sizeof(m_type));
    
    b[0] = 1;
    b[1] = -2;
    b[2] = 28;
    b[3] = 8;

    c[0] = 4;
    c[1] = 1;
    c[2] = 48;
    c[3] = 6;

    A[1][0] = 5;
    A[1][1] = -2;
    A[1][2] = 6;
    A[1][3] = 1;

    A[2][0] = 0;
    A[2][1] = 3;
    A[2][2] = 7;
    A[2][3] = -4;

    A[3][0] = 0;
    A[3][1] = 0;
    A[3][2] = 4;
    A[3][3] = 5;

    A[4][0] = 0;
    A[4][1] = 0;
    A[4][2] = 0;
    A[4][3] = 2;

    B[1][0] = 2;
    B[1][1] = 0;
    B[1][2] = 0;
    B[1][3] = 0;

    B[2][0] = 3;
    B[2][1] = 5;
    B[2][2] = 0;
    B[2][3] = 0;

    B[3][0] = 1;
    B[3][1] = -6;
    B[3][2] = 8;
    B[3][3] = 0;

    B[4][0] = -1;
    B[4][1] = 4;
    B[4][2] = -3;
    B[4][3] = 9;

    x = LSDiagSup(A, b);
    for (int i = 0; i < 4; i++) printf("x[%d] = %f \n", i, x[i]);

    x2 = LSDiagInf(B, c);
    for (int j = 0; j < 4; j++) {
        printf("x[%d] = %f \n", j, x2[j]);
    }

    free(A);
    free(B);
    free(x);
    free(x2);
    free(b);
    free(c);
}