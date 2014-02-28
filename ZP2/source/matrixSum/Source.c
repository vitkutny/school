#include <stdio.h>
#include <stdlib.h>

double** matrixSum(int, int, double**, double**);

int main(){
	int i, j;
	double matrix1[][3] = { { 1, 2, 3 }, { 4, 5, 6 } };
	double matrix2[][3] = { { 1, 2, 3 }, { 4, 5, 6 } };
	double** matrix;

	matrix = matrixSum(2, 3, matrix1, matrix2);

	for (i = 0; i < 2; i++){
		for (j = 0; j < 3; j++){
			printf("%g ", matrix[i][j]);
		}
		printf("\n");
	}

	system("PAUSE");
	return 0;
}

double **matrixSum(int rows, int cols, double first[][3], double second[][3]){
	int i, j;
	double** matrix;
	matrix = (int**)malloc(sizeof(int*)*rows);
	for (i = 0; i < rows; i++){
		matrix[i] = (int*)malloc(sizeof(int)*cols);
		for (j = 0; j < cols; j++){
			matrix[i][j] = first[i][j] + second[i][j];
		}
	}
	return matrix;
}