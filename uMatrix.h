#pragma once

class uMatrix
{
    private: 
        //You probably should have some privately accessible helper things ...
        // like data structures?
		int elementCount;
		int sqrt;
		int matrix[10000];
    public:
		//Constructor. Sets elementCount, sqrt, scaler, and fills the matrix. 
        uMatrix(int input[], int size);

		//Destructor. Deletes the array of values.  
        ~uMatrix();
        
        /**
         * @brief print
         * @input one object, self, of type uMatrix A,
         * @output a square representation of the matrix A
         */
        void print();
        
        /**
         * @brief MM Matrix Multiplication
         * @input two objects of type uMatrix self A, and parameter B
         * @output a new object of type uMatrix = A x B what is matrix multiplication? 
         * https://en.wikipedia.org/wiki/Matrix_multiplication
         */
        uMatrix MM(uMatrix B);
        
        /**
         * @brief MMf Fast Matrix Multiplication
         * @input two objects of type uMatrix self A, and parameter B
         * @output a new object of type uMatrix = A x B what is matrix multiplication? 
         * https://en.wikipedia.org/wiki/Matrix_multiplication
         */
        uMatrix MMf(uMatrix B);
        
        /**
         * @brief MA Matrix Addition
         * @input two objects of type uMatrix self A, and parameter B
         * @output a new object of type uMatrix = A + B 
         */
        uMatrix MA(uMatrix B);
        /**
         * @brief MA Fast Matrix Addition
         * @input two objects of type uMatrix, self A, and parameter B
         * @output a new object of type uMatrix = A + B 
         */
        uMatrix MAf(uMatrix B);
        
        /**
         * @brief SM Scalar Multiplication
         * @input one object, self, of type uMatrix A, and a scalar value S
         * @output a new object of type uMatrix such that every element in A is multiplied by S
         */
        uMatrix SM(int S);
        /**
         * @brief SMf Fast Scalar Multiplication
         * @input one object, self, of type uMatrix A, and a scalar value S
         * @output a new object of type uMatrix such that every element in A is multiplied by S
         */
        uMatrix SMf(int S);
        
        /**
         * @brief SA Scalar Addition
         * @input one object, self, of type uMatrix A, and a scalar value S
         * @output a new object of type uMatrix such that every element in A is increased by S
         */
        uMatrix SA(int S);
        /**
         * @brief SAf Fast Scalar Addition
         * @input one object, self, of type uMatrix A, and a scalar value S
         * @output a new object of type uMatrix such that every element in A is increased by S
         */
        uMatrix SAf(int S);
};

