#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
	int comparisons; double comparisonsDouble; int exchanges; double exchangesDouble;
} sort;

int shutdown();
void tableHeader();
int* tableRow(int);
int* randomArray(int);
void printArrayInt(int*, int, int);
sort bubbleSort(int*, int);

int main(){
	int* array;
	srand(time(NULL));

	tableHeader();
	free(tableRow(10));
	free(tableRow(20));
	free(tableRow(50));
	free(tableRow(100));
	free(tableRow(200));
	free(tableRow(500));
	free(tableRow(1000));
	free(tableRow(2000));
	array = tableRow(5000);

	printf("\n%s\n", "Prvnich 20 cisel:");
	printArrayInt(array, 5000, 20);
	printf("\n%s\n", "Poslednich 10 cisel:");
	printArrayInt(array, 5000, -10);
	free(array);

	return shutdown();
}

int shutdown(){
	printf("\n");
	system("PAUSE");
	return 0;
}

void tableHeader(){
	int i;
	printf("%6s%15s%14s\n", "pocet", "srovnani", "vymeny");
	for (i = 0; i < 35; i++){
		printf("=");
	}
	printf("\n");
}

int* tableRow(int size){
	sort bubble;
	int* array;
	array = randomArray(size);
	bubble = bubbleSort(array, size);
	printf("%6i%10i%5.2f%9i%5.2f\n", size, bubble.comparisons, bubble.comparisonsDouble, bubble.exchanges, bubble.exchangesDouble);
	return array;
}

int* randomArray(int size){
	int* array;
	int i;

	array = (int*)malloc(sizeof(int)*size);
	for (i = 0; i < size; i++){
		array[i] = (rand() * rand()) + rand();
	}
	return array;
}

void printArrayInt(int* array, int size, int range){
	int from, to, index, iteration;
	if (range == NULL){
		from = 0;
		to = size - 1;
	}
	else if (range >= 0){
		from = 0;
		to = range - 1;
	}
	else{
		from = size + range;
		to = size - 1;
	}

	printf("\n");
	for (index = from, iteration = 1; index <= to; index++, iteration++){
		printf("%i", array[index]);
		if (iteration % 5){
			printf("\t");
		}
		else if (index != to){
			printf("\n");
		}
	}
	printf("\n");
}

sort bubbleSort(int* array, int size){
	sort this;
	int i, j, temp;

	this.comparisons = 0;
	this.exchanges = 0;
	for (i = 0; i < size - 1; i++){
		for (j = 0; j < size - i - 1; j++){
			this.comparisons++;
			if (array[j + 1] < array[j]){
				this.exchanges++;
				temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp;
			}
		}
	}
	this.comparisonsDouble = (double)this.comparisons / (size*size);
	this.exchangesDouble = (double)this.exchanges / (size*size);

	return this;
}