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
    m_type aux = 0;
    row += 1;
    m_type **M = (float **)malloc(row * sizeof(m_type*));
    m_type **Mindex = (float **)malloc((row - 1) * sizeof(m_type*));
    
    for (int i = 0; i < row; i++)
    {
        M[i] = (float *)malloc((column) * sizeof(m_type));
        Mindex[i] = (float *)malloc((column) * sizeof(m_type));
    }
    
    M[0][0] = row;
    M[0][1] = column;

    Mindex[0][0] = row;
    Mindex[0][1] = column;

    // Random initialization
    for (int i = 1; i < row; i++){
        for (int j = 0; j < column; j++){
            aux = (m_type)(rand() % NUM_SIZE);
            Mindex[i][j] = aux;
            printf("%.0f \n", Mindex[i][j]);
            M[i][j] = log10(pow(M_PI, aux));
            // M[i][j] = j + 1;
        }
    }
    SaveMatrix(Mindex, "Entradas.txt");
    SaveMatrix(M, "Matrizes.txt");
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
    // int row2 = mt2[0][0];
    int column2 = mt2[0][1];
    int i, j, k;
    m_type **M = MatrixInit(row1 - 1, column2);
    float aux = 0;

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
    for(int i = 1; i < row; i++){
        for(int j = 0; j < column; j++){
            // fprintf(fp, "M[%d][%d] = %f \n", (i - 1), j, M[i][j]);
            fprintf(fp, "%f \n", M[i][j]);
        }
    }
    fprintf(fp, "\n");
    fclose(fp);
    return true;
}



