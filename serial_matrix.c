#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void fillMatrix(float *mat, int min, int max, int size) {
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		mat[i] = (rand() % (max - min + 1)) + min;
	}
}

int main(void) {
	// create the matrices, 2 that contain the numbers we want to multiply
	int row_matrix_1 = 5000; int row_matrix_2 = 5000; 
	int col_matrix_1 = 5000; int col_matrix_2 = 2000;
	
	// creating 3rd matrix to hold the final value
	int row_matrix_3 = 5000; int col_matrix_3 = 2000;

	float *matrix_one = (float*) malloc(sizeof(float)*row_matrix_1*col_matrix_1);
	float *matrix_two = (float*) malloc(sizeof(float)*row_matrix_2*col_matrix_2);
	float *matrix_three = (float*) malloc(sizeof(float)*row_matrix_3*col_matrix_3);

	float sum = 0;

	// fill the matrices with random numbers
	fillMatrix(matrix_one, 1, 100, row_matrix_1 * col_matrix_1);
	fillMatrix(matrix_two, 1, 100, row_matrix_2 * col_matrix_2);

	// multiply the matrices
	for (int i = 0; i < 10; i++) {
		for(int i = 0; i < row_matrix_1; i++ ){
			for(int j = 0; j < col_matrix_2; j++){
				sum = 0;
				for(int k = 0; k < col_matrix_1; k++){
					printf("%f * %f = %f\n", matrix_one[i*col_matrix_1 + k], matrix_two[k*col_matrix_2 + j], sum);
					sum += matrix_one[i*col_matrix_1+k]* matrix_two[k*col_matrix_2+k];
				}
				matrix_three[i* col_matrix_3 + j]=sum;
			}
		}
		printf("Multiplication done");
	}

	// free the memory allocation
	free(matrix_one);
	free(matrix_two);
	free(matrix_three);

	return 0;
// This code is contributed by Manish Kumar (mkumar2789)
}