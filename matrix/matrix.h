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
**     Return      :    Desired matrix
** ===================================================================
*/
m_type **MatrixInit(int row, int column);

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
m_type **MatrixMult(m_type **mt1, m_type **mt2);

/*
** ===================================================================
**     Method      :    MatrixPrint
**
**     Description :    Print matrix into console
**     Parameters  :    Matrix that should be printed
**     Return      :    None
** ===================================================================
*/
void MatrixPrint(m_type **M);

/*
** ===================================================================
**     Method      :    SaveMatrix
**
**     Description :    Save matrix in a .txt file
**     Parameters  :    Matrix that will be saved
**     Return      :    None
** ===================================================================
*/
bool SaveMatrix(m_type **M, char *name);

/*
** ===================================================================
**     Method      :    FrobeniusNorm
**
**     Description :    Determine Frobenius norm of a matrix
**     Parameters  :    Matrix
**     Return      :    Frobenius norm
** ===================================================================
*/
double FrobeniusNorm(m_type **M);

/*
** ===================================================================
**     Method      :    RandomInit
**
**     Description :    Initialize a matrix randomly
**     Parameters  :    Matrix
**     Return      :    Random initialized matrix
** ===================================================================
*/
m_type **RandomInit(m_type **M);

#endif