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
void insertionSort(int *array, int length){
	int i, j, t;
	for (j = 1; j <= length - 1; j++){
		t = array[j];
		i = j - 1;
		while (i >= 0 && array[i] > t){
			array[i + 1] = array[i];
			i = i - 1;
		}
		array[i + 1] = t;
	}
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
	printf("\nJakou metodu trideni chcete pouzit?\n (I - Insertion sort, B - Bubble sort, S -selection sort): ");
	fflush(stdin);
	scanf("%c", method);
	if (*method == 'I' || *method == 'B' || *method == 'S'){
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
void bubbleSort(int* array, int length){
	int i, j, temp;
	for (j = 0; j <= length - 2; j++){
		for (i = length - 1; i >= j + 1; i--){
			if (array[i] < array[i - 1]){
				temp = array[i];
				array[i] = array[i - 1];
				array[i - 1] = temp;
			}
		}
	}
}
void selectionSort(int* array, int length){
	int i, j, iMin, temp;
	for (j = 0; j <= length - 2; j++){
		iMin = j;
		for (i = j + 1; i <= length - 1; i++){
			if (array[i] < array[iMin]){
				iMin = i;
			}
		}
		temp = array[j];
		array[j] = array[iMin];
		array[iMin] = temp;
	}
}