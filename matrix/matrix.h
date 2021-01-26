/*
 * matrix.h
 *
 *  Created on: Jan 20, 2021
 *  Author:     Thiago Henrique G. Mello
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include <stdbool.h>

#define m_type float

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
bool EqualStatus(int len1, int len2);

/*
** ===================================================================
**     Method      :    MatrixInit
**
**     Description :    Matrix initialization
**     Parameters  :    Matrix size
**     Return      :    Desired matrix pointer
** ===================================================================
*/
m_type **MatrixInit(int row, int column);

/*
** ===================================================================
**     Method      :    MatrixMult
**
**     Description :    Determine the multiplication between two
**                      matrix
**     Parameters  :    Two matrix pointers that should be multiplied
**     Return      :    Matrix product pointer
** ===================================================================
*/
m_type **MatrixMult(m_type **mt1, m_type **mt2);

/*
** ===================================================================
**     Method      :    MatrixPrint
**
**     Description :    Print matrix into console
**     Parameters  :    Matrix pointer that should be printed
**     Return      :    None
** ===================================================================
*/
void MatrixPrint(m_type **M);

/*
** ===================================================================
**     Method      :    SaveMatrix
**
**     Description :    Save matrix in a .txt file
**     Parameters  :    Matrix pointer that will be saved
**     Return      :    True if operation was well succeed
** ===================================================================
*/
bool SaveMatrix(m_type **M, char *name);

/*
** ===================================================================
**     Method      :    FrobeniusNorm
**
**     Description :    Determine Frobenius norm of a matrix
**     Parameters  :    Matrix pointer
**     Return      :    Frobenius norm
** ===================================================================
*/
double FrobeniusNorm(m_type **M);

/*
** ===================================================================
**     Method      :    RandomInit
**
**     Description :    Initialize a matrix randomly
**     Parameters  :    Matrix pointer
**     Return      :    Random initialized matrix pointer
** ===================================================================
*/
m_type **RandomInit(m_type **M, char *name);

/*
** ===================================================================
**     Method      :    LSDiagSup
**
**     Description :    Solve a superior diagonal linear system
**     Parameters  :    Matrix pointer and excitation array pointer
**     Return      :    array pointer with solutions
** ===================================================================
*/
m_type *LSDiagSup(m_type **A, m_type *b);

/*
** ===================================================================
**     Method      :    LSDiagInf
**
**     Description :    Solve a inferior diagonal linear system
**     Parameters  :    Matrix pointer and excitation array pointer
**     Return      :    array pointer with solutions
** ===================================================================
*/
m_type *LSDiagInf(m_type **A, m_type *b);

/*
** ===================================================================
**     Method      :    GaussElim
**
**     Description :    Implement Gauss elimination with pivoting
**     Parameters  :    Matrix pointer
**     Return      :    Pivoted matrix pointer
** ===================================================================
*/
m_type **GaussElim(m_type **A);

#endif