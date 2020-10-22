#include <vector> 

#pragma once
class Matrix
{
private:
	int size;
	double** data;
	double laplaceRec(int w, int* WK, Matrix matrix);

public:
	Matrix(double** mArray, int size);
	int getSize();
	int getMatrixSize();
	double** getData();
	double determinant();
	double sum();
	void print();
};

