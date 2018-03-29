//DravenYorgensen.cpp
//uMatrix Project
//Draven Yorgensen
//CoSc 2030, Dr.Borowczak

//Create a program which will perform the matrix addition and multiplication of 
//2 matricies as well as the scalar addition and multiplication of those 
//matricies

#include <iostream>
#include "MatrixClass.h"
using namespace std;

uMatrix::uMatrix(int matrix[100][100], int row, int col)
{
	rows = row;
	cols = col;
	for (int i = 0; i < 100; ++i)
		for (int j = 0; j < 100; ++j)
		{
			myMatrix[i][j] = matrix[i][j];
		}
}
uMatrix::~uMatrix()
{
}

void uMatrix::print()
{

	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j)
		{
			cout << " " << myMatrix[i][j];
			if (j == cols - 1)
				cout << endl;
		}
}

uMatrix uMatrix::MM(uMatrix B,int r1, int c1, int r2, int c2, int i, int j, int k)
{
	int mult[100][100] = { 0 };

	// Initializing elements of matrix mult to 0.
	for (i = 0; i < r1; ++i)
		for (j = 0; j < c2; ++j)
		{
			mult[i][j] = 0;
		}
	//Matrix multiplication of the 2 matricies
    for (i = 0; i < r1; ++i)
		for (j = 0; j < c2; ++j)
			for (k = 0; k < c1; ++k)
			{
				mult[i][j] += myMatrix[i][k] * B.myMatrix[k][j];
			}

	return uMatrix(mult, rows, cols);
}

//uMatrix uMatrix::MMf(uMatrix B)
//{
//}

uMatrix uMatrix::MA(uMatrix B, int r1, int c1, int r2, int c2, int i, int j, int k)
{
	int sum[100][100] = { 0 };

	// Initializing elements of matrix sum to 0.
	for (i = 0; i < r1; ++i)
		for (j = 0; j < c2; ++j)
		{
			sum[i][j] = 0;
		}
	//Matrix Addition of the 2 matricies
	for (i = 0; i < r1; ++i)
		for (j = 0; j < c2; ++j)
			sum[i][j] = myMatrix[i][j] + B.myMatrix[i][j];
	return uMatrix(sum, rows, cols);
}

//uMatrix uMatrix::MAf(uMatrix B)
//{
//}

uMatrix uMatrix::SM(uMatrix B, int sc, int r1, int c1, int r2, int c2, int i, int j, int k)
{
	int scalar[100][100] = { 0 };
	//Scalar multiplication of the 2 matricies
	for (j = 0; j < r1; ++j)
		for (k = 0; k < c1; ++k)
		{
			scalar[j][k] = sc * myMatrix[j][k];
		}
	return uMatrix(scalar, rows, cols);
}

//uMatrix uMatrix::SMf(int S)
//{
//}

uMatrix uMatrix::SA(uMatrix B, int sc, int r1, int c1, int r2, int c2, int i, int j, int k)
{
		int scalar[100][100] = { 0 };
				//Scalar multiplication of the 2 matricies
					for (j = 0; j < r1; ++j)
						for (k = 0; k < c1; ++k)
						{
							scalar[j][k] = sc + myMatrix[j][k];
							
						}
							return uMatrix(scalar, rows, cols);
}

//uMatrix uMatrix::SAf(int S)
//{
//}
