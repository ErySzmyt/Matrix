// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <time.h> 
#include "Matrix.h"
#include "MatrixGenerator.h"


int main()
{
    // initialize random seed
    srand(time(NULL));

    std::cout << "Generated Random Matrix:" << std::endl;

    Matrix matrix = MatrixGenerator::generateRandom(4);

    matrix.print();

    std::cout << "Matrix sum: " << matrix.sum() << std::endl;
    std::cout << "Matrix determinant: " << matrix.determinant() << std::endl;

}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu