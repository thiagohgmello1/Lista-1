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

#define m_type double
#define NUM_SIZE 37
#define dec 5

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
    m_type **M = (m_type **)calloc(row, sizeof(m_type*));
    
    
    for (int i = 0; i < row; i++){
        M[i] = (m_type *)calloc((column), sizeof(m_type));
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

    fp = fopen(name, "w");
    if(fp == NULL) {
        return false;
    }

    fprintf(fp, "row: %d \ncolumn: %d\n", (row - 1), column);
    for(int i = 1; i < row; i++){
        for(int j = 0; j < column; j++){
            if(strcmpi(name, "Matrizes.txt") == 0){
                fprintf(fp, "%.15f ", M[i][j]);
            }
            else fprintf(fp, "%.15f ", M[i][j]);
        }
        fprintf(fp, "\n");
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
        }
    }
    norm = sqrt(sum);
    return norm;
}

/*
** ===================================================================
**     Method      :    EuclidianNorm
**
**     Description :    Determine Euclidian norm of a array
**     Parameters  :    Array pointer
**     Return      :    Euclidian norm
** ===================================================================
*/
double EuclidianNorm(m_type *array, int size){
    double sum = 0, norm = 0;

    for (int i = 0; i < size; i++){
        sum += pow(array[i], 2);
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
m_type **RandomInit(m_type **M, char *name){
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
            M[i][j] = log10(pow(M_PI, aux));
            // M[i][j] = aux;
        }
    }
    SaveMatrix(Mindex, name);
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
    double sum = 0;

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

    for (int i = 2; i < row; i++){
        for (int j = 0; j <= (i - 2); j++){
            sum -= A[i][j] * x[j];
        }
        x[i - 1] = (sum + b[i - 1])/A[i][i - 1];
        sum = 0;
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
void GaussElim(m_type **A, m_type *b){

    float ep = 0.000001;
    int row = A[0][0];
    int column = A[0][1];
    int pos = 0;
    int count = 0;
    m_type pivot = 0;
    m_type m = 0;
    m_type det = 1;
    m_type baux = 0;
    m_type *Aaux = (m_type *)malloc((column) * sizeof(m_type));

    m_type **M = (m_type **)malloc((row) * sizeof(m_type*));

    for (int i = 0; i < row; i++){
        M[i] = (m_type *)malloc((column) * sizeof(m_type));
    }

    // Pivoting process
    for (int j = 0; j < column; j++){
        // Pivot element definition
        for (int i = 1; i < row; i++){
            if ((j == 0) && (abs(A[i][j]) > pivot)){
                pivot = A[i][j];
                pos = i;
            }
            else if ((abs(A[i][j - 1]) <= ep) && (abs(A[i][j]) > pivot)){
                pivot = A[i][j];
                pos = i;
            }
        }
        // Pivoting process
        for (int i = 1; i < row; i++){
            m = -A[i][j] / pivot;
            if ((j == 0) && (i != pos)){
                // b[i - 1] += round((m * b[pos - 1])*pow(10,dec))/pow(10,dec);
                b[i - 1] += m * b[pos - 1];
            }
            else if ((abs(A[i][j - 1]) <= ep) && (i != pos)){
                // b[i - 1] += round((m * b[pos - 1])*pow(10,dec))/pow(10,dec);
                b[i - 1] += m * b[pos - 1];
            }
            for (int j2 = j; j2 < column; j2++){
                if ((j == 0) && (i != pos)){
                    A[i][j2] += m * A[pos][j2];
                }
                else if ((abs(A[i][j - 1]) <= ep) && (i != pos)){
                    A[i][j2] += m * A[pos][j2];
                }
            }
        }
        pivot = 0;
    }

    FILE *fp;
    fp = fopen("b1.txt", "w");
    fprintf(fp, "size: %d \n", column);
    for(int i = 0; i < column; i++){
            fprintf(fp, "%.15f ", b[i]);
    }

    SaveMatrix(A,"A1.txt");
    // Superior diagonal matrix mountage
    for (int j = 0; j < column; j++){
        for (int i = 1; i < row; i++){
            if ((abs(A[i][j]) > ep) && (i != (j + 1))){
                if (j == 0){
                    pos = i;
                    count += 1;
                    
                    baux = b[pos - 1];
                    b[pos - 1] = b[j];
                    b[j] = baux;
                    
                    Aaux = A[pos];
                    A[pos] = A[j + 1];
                    A[j + 1] = Aaux;
                    break;
                }
                else if (abs(A[i][j - 1]) < ep){
                    pos = i;
                    count += 1;
                    
                    baux = b[pos - 1];
                    b[pos - 1] = b[j];
                    b[j] = baux;
                    
                    Aaux = A[pos];
                    A[pos] = A[j + 1];
                    A[j + 1] = Aaux;
                    break;
                }
                
            }
        }
        
    }
    SaveMatrix(A,"A2.txt");
    
    for (int i = 1; i < row; i++){
        det *= A[i][i - 1];
    }
    det *= pow(-1, count);
    printf("det = %f \n", det);

    Aaux = NULL;
    free(Aaux);
    DeallocM(M);
}

/*
** ===================================================================
**     Method      :    DeallocM
**
**     Description :    Dealloc a matrix pointer
**     Parameters  :    Matrix pointer
**     Return      :    None
** ===================================================================
*/
void DeallocM(m_type **A){
    int row = A[0][0];
    for (int i = 0; i < row; i++){
        A[i] = NULL;
        free(A[i]);
    }
    A = NULL;
    free(A);
}
