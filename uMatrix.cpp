#include <iostream>
using namespace std;
#include "uMatrix.h"

uMatrix::uMatrix(int input[], int size)
{
	//Finding Squareroot. Idea for finding squareroot found from 
	//"Himanshu"
	//March 3rd, 2016
	//https://stackoverflow.com/questions/19611198/finding-square-root-without-using-sqrt-function

	elementCount = size;//Sets passed in value for the number of elements in the matrix.
	int high = size;
	int low = 1;
	int mid = 1;
	while (mid*mid != size) {
		mid = low + ((high - low) / 2); //finds the middle between 'high' and 'low'
		if (mid*mid > size) {
			high = mid;
		}
		else {
			low = mid;
		}
	}
	sqrt = mid;
	//storing input array as the matrix array. 
	for (int i = 0; i < size; i++) {
		matrix[i] = input[i];
	}
}

uMatrix::~uMatrix()
{
	sqrt = 0;
	elementCount = 0;
}

void uMatrix::print()
{
	int breakIndex = 0; //a seperate index that will be tested for when to break the rows
	for (int h = 0; h < sqrt; h++) {
		cout << "___";
	}
	cout << "\n";
	for (int i = 0; i < elementCount; i++) {
		cout << matrix[i] << " ";
		breakIndex++;
		if (breakIndex == sqrt) {
			cout << "\n";//starts a new line to make the matrix look like a 'squareroot x squareroot' box
			breakIndex = 0;
		}
	}
	cout << endl;
	for (int j = 0; j < sqrt; j++) {
		cout << "___";
	}
	cout << endl;
}

uMatrix uMatrix::MM(uMatrix B)
{
	//algorithm based off "Iterative algorithm" found @ https://en.wikipedia.org/wiki/Matrix_multiplication_algorithm
	//1d application found by
	//Tom Teman
	//April 20th, 2012
	//https://stackoverflow.com/questions/10252621/matrix-multiplication-using-1d-arrays

	int tmp[10000];//we have to use temporary array to store products because the same element in a position will be used more than once. 
	for (int i = 0; i < sqrt; i++) {
		for (int j = 0; j < sqrt; j++) {
			int sum = 0;
			for (int k = 0; k < sqrt; k++)
				sum = sum + matrix[i * sqrt + k] * B.matrix[k * sqrt + j];
			tmp[i * sqrt + j] = sum;
		}
	}
	uMatrix output = uMatrix(tmp, elementCount);
	return output;
}

uMatrix uMatrix::MMf(uMatrix B)
{
	//algorithm based off "Iterative algorithm" found @ https://en.wikipedia.org/wiki/Matrix_multiplication_algorithm
	//1d application found by
	//Tom Teman
	//April 20th, 2012
	//https://stackoverflow.com/questions/10252621/matrix-multiplication-using-1d-arrays

	int tmp[10000];//we have to use temporary array to store products because the same element in a position will be used more than once. 
	for (int i = 0; i < sqrt; i++) {
		for (int j = 0; j < sqrt; j++) {
			int sum = 0;
			for (int k = 0; k < sqrt; k++)
				sum = sum + matrix[i * sqrt + k] * B.matrix[k * sqrt + j];
			tmp[i * sqrt + j] = sum;
		}
	}
	uMatrix output = uMatrix(tmp, elementCount);
	return output;
}	

uMatrix uMatrix::MA(uMatrix B)
{
	int tmp[10000];
	//Matrix addition adds numbers together that are in the same position in the matrix.
	for (int i = 0; i < sqrt; i++) {
		for (int j = 0; j < sqrt; j++) {
			tmp[(sqrt*i) + j] = matrix[(sqrt*i) + j] + B.matrix[(sqrt*i) + j];
		}
	}
	//Creating new uMatrix to be returned. 
	uMatrix output = uMatrix(tmp, elementCount);
	return output;
}


uMatrix uMatrix::MAf(uMatrix B)
{
	/*
	According to method 8, found @ 
	http://nadeausoftware.com/articles/2012/06/c_c_tip_how_loop_through_multi_dimensional_arrays_quickly
	using a single loop with a linear array and incrementing index
	is the about as fast as this simple process can get. 
	*/
	int index = 0;
	//since our matrices are square, we only have to loop once. (sqrt * sqrt = elementCount)
	while (index != elementCount) {
		matrix[index] = matrix[index] + B.matrix[index];
		index++;
	}
	uMatrix output = uMatrix(matrix, elementCount);
	return output;
}

uMatrix uMatrix::SM(int S)
{
	//multiplying every element in the matrix by a singular value.
	int tmp[10000];
	for (int i = 0; i < sqrt; i++) {
		for (int j = 0; j < sqrt; j++) {
			tmp[(sqrt*i) + j] = matrix[(sqrt*i) + j] + S; //storing results in 
		}
	}
	uMatrix output = uMatrix(tmp, elementCount);
	return output;
}

uMatrix uMatrix::SMf(int S)
{
	//multiplying every element in the matrix by a singular value.
	//since the two matrices are the square, we can loop through this process with one loop. 
	for (int i = 0; i < elementCount; i++) {
		matrix[i] = matrix[i] * S;
	}
	uMatrix output = uMatrix(matrix, elementCount);
	return output;
}

uMatrix uMatrix::SA(int S)
{
	//Adding every element in the matrix by a singular value.
	for (int i = 0; i < sqrt; i++) {
		for (int j = 0; j < sqrt; j++) {
			matrix[(sqrt*i) + j] = matrix[(sqrt*i) + j] + S;
		}
	}
	uMatrix output = uMatrix(matrix, elementCount);
	return output;
}

uMatrix uMatrix::SAf(int S)
{
	//Adding every element in the matrix by a singular value.
	//since the two matrices are the square, we can loop through this process with one loop. 
	for (int i = 0; i < elementCount; i++) {
		matrix[i] = matrix[i] + S;
	}
	uMatrix output = uMatrix(matrix, elementCount);
	return output;
}