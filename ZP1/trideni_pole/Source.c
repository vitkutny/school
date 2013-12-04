#include <stdio.h>
#include <stdlib.h>

int restart();
int shutdown();
void insertionSort(int*, int);
void bubbleSort(int*, int);
void selectionSort(int*, int);
void printArrayOFInt(int*, int);
void sort_method_select(char*);
void array_length_select(int*);
void array_random(int*, int);
void quickSort(int*, int, int);
int quickSortPartition(int*, int, int);
void swap(int*, int*);

int main(){
	int length;
	int* array;
	char method;

	array_length_select(&length);
	sort_method_select(&method);

	array = (int*)malloc(sizeof(int)*length);
	array_random(array, length);

	printArrayOFInt(array, length);

	switch (method){
	case 'I':
		printf("\nByl pouzit insertion sort.\n");
		insertionSort(array, length);
		break;
	case 'B':
		printf("\nByl pouzit bubble sort.\n");
		bubbleSort(array, length);
		break;
	case 'S':
		printf("\nByl pouzit selection sort.\n");
		selectionSort(array, length);
		break;
	case 'Q':
		printf("\nByl pouzit quick sort.\n");
		quickSort(array, 0, length - 1);
		break;
	};

	printArrayOFInt(array, length);

	return shutdown();
}
int restart(){
	system("CLS");
	return main();
}
int shutdown(){
	printf("\n\n");
	system("PAUSE");
	return 0;
}
void printArrayOFInt(int *array, int length){
	int i = 0;
	printf("\nArray print:\n");
	for (i = 0; i < length; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
}
void sort_method_select(char* method){
	printf(
		"\nI - Insertion sort"
		"\nB - Bubble sort"
		"\nS - Selection sort"
		"\nQ - Quick sort"
		"\nJakou metodu trideni chcete pouzit? "
		);
	fflush(stdin);
	scanf("%c", method);
	if (*method == 'I' || *method == 'B' || *method == 'S' || *method == 'Q'){
		return;
	}
	else{
		sort_method_select(method);
	}
	return;
}
void array_length_select(int* length){
	printf("Kolik chcete vygenerovat nahodnych cisel? ");
	scanf("%d", length);

	if (*length < 1){
		printf("\nPocet nahodnych cisel musi byt vetsi nez nula.\n\n");
		fflush(stdin);
		return array_length_select(length);
	}
}
void array_random(int* array, int length){
	int i;
	for (i = 0; i < length; i++){
		array[i] = rand() % 100;
	}
}
void swap(int* a, int* b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void bubbleSort(int* array, int length){
	int i, j;
	for (j = 1; j <= length - 1; j++){
		for (i = length - 1; i >= j; i--){
			if (array[i] < array[i - 1]){
				swap(&array[i], &array[i - 1]);
			}
		}
	}
}
void insertionSort(int *array, int length){
	int i, j, temp;
	for (j = 1; j <= length - 1; j++){
		temp = array[j];
		for (i = j; i && array[i - 1] > temp; i--){
			array[i] = array[i - 1];
		}
		array[i] = temp;
	}
}
void selectionSort(int* array, int length){
	int i, j, temp;
	for (j = 1; j <= length - 1; j++){
		temp = j - 1;
		for (i = j; i <= length - 1; i++){
			if (array[i] < array[temp]){
				temp = i;
			}
		}
		swap(&array[j - 1], &array[temp]);
	}
}
void quickSort(int* array, int left, int right){
	int pivot;
	if (left < right){
		pivot = quickSortPartition(array, left, right);
		quickSort(array, left, pivot - 1);
		quickSort(array, pivot + 1, right);
	}
}
int quickSortPartition(int* array, int left, int right){
	int i;

	for (i = left; i <= right - 1; i++){
		if (array[i] <= array[right]){
			swap(&array[left], &array[i]);
			left++;
		}
	}
	swap(&array[left], &array[right]);

	return left;
}