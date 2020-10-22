#include "Matrix.h"

#include <iostream>
#include <cstdlib>
#include <limits> 
#include <vector> 

/**
* Constructor
* @param mArray an matrix array
* @param size size od matrix
*/
Matrix::Matrix(double** mArray, int size)
{
    this->data = mArray;
    this->size = size;
}

/**
* @returns a size sqr(of rows*columns)
*/
int Matrix::getMatrixSize()
{
    return this->size;
}

/**
* @returns a real size of matrix data length
*/
int Matrix::getSize()
{
    return (int)pow(this->size, 2);
}

/**
* @returns an matrix of data
*/
double** Matrix::getData()
{
    return this->data;
}

/**
* @returns the determinant of the Matrix
*/
double Matrix::determinant()
{
    int* WK;                                     //new columns pointer
    WK = new int[this->size];                    // initializing pointer

    for (int i = 0; i < this->size; i++)         // filing pointer with column number representation
        WK[i] = i;

    //returning an recurencial function that will 'eventually' return an expected result
    return this->laplaceRec(0, WK, Matrix(this->data, this->size));
}


/**
* An implementaion of Laplace's recurrencial algorithm for matrix's determinant
*
* @param s size of matrix
* @param w starting row
* @param *WK An pointer containing column's number
* @param matrix data to pass
*
* @returns the determinant of the Matrix
*/
double Matrix::laplaceRec(int r, int* WK, Matrix matrix)
{
    int* KK;        //new columns vector
    int    k, m;    // varible for vector and multiplier
    double e;       // varible expansion

    if (matrix.getMatrixSize() == 1)                     // if the size of matrix is equal to 1 the tle last cell is the answer
        return matrix.getData()[r][WK[0]];    // 1x1 matrix the value of the first cell is an answer

    KK = new int[matrix.getMatrixSize() - 1];            // dynamic pointer for colums

    e = 0;                          // seting expansion to 0
    m = 1;                          // initial multiplier

    for (int i = 0; i < matrix.getMatrixSize(); i++)       // loop for calculating expansion
    {
        k = 0;                       // creating new vector for recursion

        for (int j = 0; j < matrix.getMatrixSize() - 1; j++) // KK should be one column smaller compare to WK 
        {
            if (k == i) k++;          // skiping current column
            KK[j] = WK[k++];     // coping rest of vector to KK pointer
        }

        Matrix matrix2 = Matrix(matrix.getData(), (matrix.getMatrixSize() - 1));

        e += m * matrix2.getData()[r][WK[i]] * this->laplaceRec(r + 1, KK, matrix2); //calculating expansion
        m = -m;                      // new multiplier
    }


    delete[] KK;                   // removing an dynamic array
    return e;                      // returning calculated expansion
}

/**
* @returns an sum od matrix values
*/
double Matrix::sum()
{
    double result = 0;
    for (int x = 0; x < this->size; x++)
        for (int y = 0; y < this->size; y++)
            result += this->data[x][y];

    return result;
}

/**
* Printing entire matrix data in console
*/
void Matrix::print()
{
    for (int x = 0; x < this->size; x++) {
        std::cout << "[";
        for (int y = 0; y < this->size; y++)
            std::cout << "\t" << this->data[x][y] << "\t";
        std::cout << "]" << std::endl;
    }
}
