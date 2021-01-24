/*
 * matrix.c
 *
 *  Created on: Jan 20, 2021
 *  Author:     Thiago Henrique G. Mello
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "matrix.h"
#include <string.h>

#define m_type float
#define NUM_SIZE 37

/*
** ===================================================================
**     Method      :    bool EqualStatus(int len1, int len2)
**
**     Description :    Determine if two matrix can be multiplied
**     Parameters  :    Number of columns from the first matrix and
**                      number of rows from the second matrix
**     Return      :    boolean indicating if the multiplication is
**                      possible
** ===================================================================
*/
bool EqualStatus(int len1, int len2){
    if (len1 == len2)
    {
        return true;
    } else return false;
}

/*
** ===================================================================
**     Method      :    MatrixInit
**
**     Description :    Matrix initialization
**     Parameters  :    Matrix size
**     Return      :    Desired matrix
** ===================================================================
*/
m_type **MatrixInit(int row, int column){
    row += 1;
    m_type **M = (m_type **)malloc(row * sizeof(m_type*));
    
    
    for (int i = 0; i < row; i++){
        M[i] = (m_type *)malloc((column) * sizeof(m_type));
    }
    
    M[0][0] = row;
    M[0][1] = column;

    return M;
}

/*
** ===================================================================
**     Method      :    MatrixMult
**
**     Description :    Determine the multiplication between two
**                      matrix
**     Parameters  :    Two matrix that should be multiplied
**     Return      :    Matrix product
** ===================================================================
*/
m_type **MatrixMult(m_type **mt1, m_type **mt2){
    int row1 = mt1[0][0];
    int column1 = mt1[0][1];
    int column2 = mt2[0][1];
    int i, j, k;
    m_type **M = MatrixInit(row1 - 1, column2);
    m_type aux = 0;

    for(i = 1; i < row1; i++){
        for(j = 0; j < column2; j++){
            for(k = 0; k < column1; k++){
                aux += mt1[i][k] * mt2[(k + 1)][j];
            }
            M[i][j] = aux;
            aux = 0;
        }
    }
    return M;
}

/*
** ===================================================================
**     Method      :    MatrixPrint
**
**     Description :    Print matrix into console
**     Parameters  :    Matrix that should be printed
**     Return      :    None
** ===================================================================
*/
void MatrixPrint(m_type **M){
    int row = M[0][0];
    int column = M[0][1];
    printf("row: %d \ncolumn: %d \n",row - 1, column);
    for(int i = 1; i < row; i++){
        for(int j = 0; j < column; j++){
            printf("M[%d][%d] = %f \n", (i - 1), j, M[i][j]);
        }
    }
}

/*
** ===================================================================
**     Method      :    SaveMatrix
**
**     Description :    Save matrix in a .txt file
**     Parameters  :    Matrix that will be saved
**     Return      :    None
** ===================================================================
*/
bool SaveMatrix(m_type **M, char *name){
    FILE *fp;
    int row = M[0][0];
    int column = M[0][1];

    fp = fopen(name, "a");
    if(fp == NULL) {
        return false;
    }

    fprintf(fp, "row: %d \ncolumn: %d\n", (row - 1), column);
    for(int i = 1; i < row; i++){
        for(int j = 0; j < column; j++){
            if(strcmpi(name, "Entradas.txt") == 0){
                fprintf(fp, "%.0f \n", M[i][j]);
            }
            else fprintf(fp, "%.15f \n", M[i][j]);
        }
    }
    fprintf(fp, "\n");
    fclose(fp);
    return true;
}

/*
** ===================================================================
**     Method      :    FrobeniusNorm
**
**     Description :    Determine Frobenius norm of a matrix
**     Parameters  :    Matrix
**     Return      :    Frobenius norm
** ===================================================================
*/
double FrobeniusNorm(m_type **M){
    double sum = 0, norm = 0;
    int row, column;
    row = M[0][0];
    column = M[0][1];
    for(int i = 1; i < row; i++){
        for(int j = 0; j < column; j++){
            sum += pow(M[i][j], 2);
            // printf("soma: %f     valor: %f \n", sum, M[i][j]);
        }
    }
    norm = sqrt(sum);
    return norm;
}

/*
** ===================================================================
**     Method      :    RandomInit
**
**     Description :    Initialize a matrix randomly
**     Parameters  :    Matrix
**     Return      :    Random initialized matrix
** ===================================================================
*/
m_type **RandomInit(m_type **M){
    int aux;
    int row = M[0][0];
    int column = M[0][1];
    m_type **Mindex = (m_type **)malloc((row) * sizeof(m_type*));

    for (int i = 0; i < row; i++){
        Mindex[i] = (m_type *)malloc((column) * sizeof(m_type));
    }

    Mindex[0][0] = row;
    Mindex[0][1] = column;

    // Random initialization
    for (int i = 1; i < row; i++){
        for (int j = 0; j < column; j++){
            aux = (rand() % NUM_SIZE);
            Mindex[i][j] = aux;
            // printf("%.0f \n", Mindex[i][j]);
            M[i][j] = log10(pow(M_PI, aux));
        }
    }
    SaveMatrix(Mindex, "Entradas.txt");
    return M;
}

/*
** ===================================================================
**     Method      :    LSDiagSup
**
**     Description :    Solve a superior diagonal linear system
**     Parameters  :    Matrix pointer
**     Return      :    array pointer with solutions
** ===================================================================
*/
m_type *LSDiagSup(m_type **A, m_type *b){
    int row = A[0][0];
    int column = A[0][1];
    m_type *x = (m_type *)malloc((row - 1) * sizeof(m_type));
    m_type sum = 0;

    x[row - 2] = b[row - 2]/A[row - 1][column - 1]; // Solution of element xn

    for (int i = (row - 2); i >= 0; i--){
        for (int j = i + 1; j < column; j++){
            sum -= A[i + 1][j] * x[j];
        }
        x[i] = (sum + b[i])/A[i + 1][i];
        sum = 0;
        // printf("x[%d] = %f \n", i, x[i]);
    }
    return x;
}

/*
** ===================================================================
**     Method      :    LSDiagInf
**
**     Description :    Solve a inferior diagonal linear system
**     Parameters  :    Matrix pointer and excitation array pointer
**     Return      :    array pointer with solutions
** ===================================================================
*/
m_type *LSDiagInf(m_type **A, m_type *b){
    int row, column;
    row = A[0][0];
    column = A[0][1];
    m_type *x = (m_type *)malloc((row - 1) * sizeof(m_type));
    m_type sum = 0;

    x[0] = b[0]/A[1][0]; // Solution of element x1
    // printf("%f \n", x[0]);

    for (int i = 2; i < row; i++){
        for (int j = 0; j <= (i - 2); j++){
            sum -= A[i][j] * x[j];
        }
        x[i - 1] = (sum + b[i - 1])/A[i][i - 1];
        sum = 0;
        // printf("x[%d] = %f \n", i - 1, x[i - 1]);
    }
    return x;
}

/*
** ===================================================================
**     Method      :    GaussElim
**
**     Description :    Implement Gauss elimination with pivoting
**     Parameters  :    Matrix pointer and excitation array pointer
**     Return      :    Pivoted matrix pointer
** ===================================================================
*/
m_type *GaussElim(m_type **A, m_type *b){
    
}
