/*
* This C program can multiply any two square or rectangular matrices.
* The below program multiplies two square matrices of size 4 * 4.
* There is also an example of a rectangular matrix for the same code (commented below).
* We can change the Matrix value with the number of rows and columns (from MACROs) for Matrix-1
* and Matrix-2 for different dimensions.
*/

/*
* Note: i- The number of columns in Matrix-1 must be equal to the number of rows in Matrix-2.
*	 ii- Output of multiplicationof Matrix-1 and Matrix-2, results with equalto the number
*		 of rows of Matrix-1 and thenumber of columns of Matrix-2 i.e. rslt[R1][C2].
*/

#include <stdio.h>
#include <stdlib.h>


// Edit MACROs here, according to your Matrix Dimensions for mat1[R1][C1] and mat2[R2][C2]
#define R1 4		 // number of rows in Matrix-1
#define C1 4		 // number of columns in Matrix-1
#define R2 4		 // number of rows in Matrix-2
#define C2 4		 // number of columns in Matrix-2

void mulMat(int mat1[][C1], int mat2[][C2]) {
	int rslt[R1][C2];

	printf("Multiplication of given two matrices is:\n\n");

	for (int i = 0; i < R1; i++) {
		for (int j = 0; j < C2; j++) {
			rslt[i][j] = 0;

			for (int k = 0; k < R2; k++) {
				rslt[i][j] += mat1[i][k] * mat2[k][j];
			}

			printf("%d\t", rslt[i][j]);
		}

		printf("\n");
	}
}

void fillMatrix(int min, int max, int size, float *mat) {
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		mat[i] = (rand() % (max - min + 1)) + min;
	}
}

int main(void) {

	// create the matrices, 2 that contain the numbers we want to multiply
	int row_matrix_1 = 900; int row_matrix_2 = 900; 
	int col_matrix_1 = 900; int col_matrix_2 = 600;
	
	// creating 3rd matrix to hold the final value
	int row_matrix_3 = 900; int col_matrix_3 = 600;

	float *matrix_one = (float*) malloc(sizeof(float)*row_matrix_1*col_matrix_1);
	float *matrix_two = (float*) malloc(sizeof(float)*row_matrix_2*col_matrix_2);
	float *matrix_three = (float*) malloc(sizeof(float)*row_matrix_3*col_matrix_3);

	float sum = 0;

	for(int i = 0; i < row_matrix_1; i++ ){
		for(int j = 0; j < col_matrix_2; j++){
			sum = 0;
			for(int k = 0; k < col_matrix_1; k++){
				sum += matrix_one[i*col_matrix_1+k]* matrix_two[k*col_matrix_2+k];
			}
			matrix_three[i* col_matrix_3 + j]=sum;
		}
	}
// This code is contributed by Manish Kumar (mkumar2789)
}