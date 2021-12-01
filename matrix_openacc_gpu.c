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
	int row_matrix_1 = 3000; int row_matrix_2 = 3000;
	int col_matrix_1 = 3000; int col_matrix_2 = 2700;
	
	// creating 3rd matrix to hold the final value
	int row_matrix_3 = 3000; int col_matrix_3 = 2700;

	float *matrix_one = (float*) malloc(sizeof(float)*row_matrix_1*col_matrix_1);
	float *matrix_two = (float*) malloc(sizeof(float)*row_matrix_2*col_matrix_2);
	float *matrix_three = (float*) malloc(sizeof(float)*row_matrix_3*col_matrix_3);

	float sum = 0;

	// fill the matrices with random numbers
	fillMatrix(matrix_one, 1, 100, row_matrix_1 * col_matrix_1);
	fillMatrix(matrix_two, 1, 100, row_matrix_2 * col_matrix_2);

	
	// start clock
	clock_t start = clock();

	// multiply the matrices

	// print that multiplication is happening
	printf("Multiplying the matrices...\n");
#pragma acc loop
	for (int i = 0; i < 10; i++) {
		#pragma acc data copyin(row_matrix_1, col_matrix_1,row_matrix_2, col_matrix_2) copy(col_matrix_3, row_matrix_3)
		for(int i = 0; i < row_matrix_1; i++ ){
			for(int j = 0; j < col_matrix_2; j++){
				sum = 0;
				#pragma acc loop reduction(+:sum)
				for(int k = 0; k < col_matrix_1; k++){
					//printf("%f * %f = %f\n", matrix_one[i*col_matrix_1 + k], matrix_two[k*col_matrix_2 + j], sum);
					sum += matrix_one[i*col_matrix_1+k]* matrix_two[k*col_matrix_2+k];
				}
				matrix_three[i* col_matrix_3 + j]=sum;
			}
		}
	}
	printf("Multiplication done\n");

	// free the memory allocation
	free(matrix_one);
	free(matrix_two);
	free(matrix_three);

	// stop clock
	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Time: %f seconds\n", time_spent);

	return 0;
// This code is contributed by Manish Kumar (mkumar2789)
}