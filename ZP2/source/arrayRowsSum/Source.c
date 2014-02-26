#include <stdio.h>
#include <stdlib.h>
#define ROWS 5

int* arrayRowsSum(int, int);
int shutdown();

int main()
{
	int array[ROWS][4] = { { 4, 2, 5, 6 }, { 1, 8, 5, 9 }, { 14, 22, 54, 26 }, { 1, 10, 8, 7 }, { 4, 12, 52, 63 } }, i;
	int* sums = arrayRowsSum(array, ROWS);

	for (i = 0; i < ROWS; i++)
		printf("Sum of row %d is %d.\n", i, sums[i]);

	return shutdown();
}

int* arrayRowsSum(int array[][4], int rows)
{
	int i, j;
	int* sums;
	sums = (int*)malloc(sizeof(int)*rows);

	for (i = 0; i < rows; i++){
		sums[i] = 0;
		for (j = 0; j < 4; j++){
			sums[i] += array[i][j];
		}
	}

	return sums;
}

int shutdown(){
	printf("\n\n");
	system("PAUSE");
	return 0;
}
