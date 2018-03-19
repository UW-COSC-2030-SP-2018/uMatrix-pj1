#include <iostream>
#include "uMatrix.h"
using namespace std;

#include<fstream>
using std::ifstream;

int main(int argc, char **argv)
{
	int matrixA[10000];//allocating space for the piped in data for the first matrix
	int matrixB[10000];//allocating space for the piped in data for the second matrix
	int S;//holds the scaler value piped in after the matrix data

	//opening file
	ifstream file;
	char fileName[100];
	cout << "enter file... " << endl; //prompting user for file...
	cin >> fileName;
	file.open(fileName);//attempting to open...
	while (!file.is_open())//looping until user enters a readable file
	{
		cout << "enter file... " << endl;
		cin >> fileName;
		file.open(fileName);
	}
	int index = 0;//Keeps track of how many elements are passed into a matrix
	int number;//acts as a placeholder for int values while reading the file
	char c;//acts as a placeholder for char values while reading the file
	
	//Storing the first set of numbers for matrix A
	while(file >> number>>c&&(c==','||c=='\n'))
	{
		if (c == '\n') break;
		matrixA[index] = number;
		index++;
	} 
	matrixA[index] = number;

	file.putback(c);//while loop reads begining of next line as a character before breaking. 
	//the putback() method allows for the input stream to take one step back 

	index = 0;//resets the index so the numbers get stored in the righ place
	//Storing the second set of numbers for matrix B
	while (file >> number >> c && (c == ',' || c == 'n'))
	{
		if (c == 'n') break;
		matrixB[index] = number;
		index++;
	}
	matrixB[index]=number;

	file.putback(c);
	file >> S;//reads in last value as the scaler value.
	file.close();
	index++;//if we increment the index by one, it will give us the 
	//amount of elements in each matrix (assuming they are the same size)

    uMatrix A(matrixA, index);
    uMatrix B(matrixB, index);
	uMatrix Af(matrixA, index);//This will be used to test the fast functions.
	uMatrix Bf(matrixB, index);//Using identical matrices for the slow and fast functions will help to see if they're both working the same;
    
	cout << "First Input: Matrix A " << endl;
	A.print();
	cout << "Second Input: Matrix B " << endl;
	B.print();

    //How about multiplying those two and creating a new uMatrix C?
    uMatrix C = A.MM(B);
	cout << "A * B: Matrix C " << endl;
	C.print();

    //Add C to B? 
    uMatrix D = B.MA(C);
	cout << "C + B: Matrix D " << endl;
	D.print();

    //Scalar Add to A?
    uMatrix E = A.SA(S);
	cout << "A + "<<S<<": Matrix E " << endl;
	E.print();

	//Scaler multiplication to A?
	uMatrix F = A.SM(S);
	cout << "A * " << S << ": Matrix F " << endl;
	F.print();

	cout << "...:::  End of slow function testing  :::..." << endl << endl;

	//Testing fast functions
	cout << "First Input: Matrix Af " << endl;
	Af.print();
	cout << "Second Input: Matrix Bf " << endl;
	Bf.print();

	//How about multiplying those two and creating a new uMatrix C?
	uMatrix Cf = Af.MMf(Bf);
	cout << "Af * Bf: Matrix Cf " << endl;
	Cf.print();

	//Add C to B? 
	uMatrix Df = Bf.MAf(C);
	cout << "Cf + Bf: Matrix Df " << endl;
	Df.print();

	//Scalar Add to A?
	uMatrix Ef = Af.SAf(S);
	cout << "Af + " << S << ": Matrix Ef " << endl;
	Ef.print();

	cout << "...:::   End of fast function testing   :::..." << endl << endl;
    
	return 0;
}
