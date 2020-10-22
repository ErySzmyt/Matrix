// Matrices.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h> 
#include "Matrix.h"
#include "MatrixGenerator.h"


int main()
{
    // initialize random seed
    srand(time(NULL));

    std::cout << "Generated Random Matrice:" << std::endl;

    Matrix matrice = MatrixGenerator::generateRandom(4);

    matrice.print();

    std::cout << "Matrice sum: " << matrice.sum() << std::endl;
    std::cout << "Matrice determinant: " << matrice.determinant() << std::endl;

}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu