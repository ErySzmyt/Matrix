#include "MatrixGenerator.h"

#include <stdlib.h>

Matrix MatrixGenerator::generateRandom(int m_size)
{
    double** res = new double* [m_size];

    for (int x = 0; x < m_size; x++) {
        res[x] = new double[m_size];    // creating an node

        for (int y = 0; y < m_size; y++)
            res[x][y] = (int)(rand() % 10 + 1);
    }

    return Matrix(res, m_size);
}
