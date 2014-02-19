#include <stdio.h>

int shutdown();
int arraySearch(int*, int, int, int);
void arraySearchPrint(int i);

int main()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };

	arraySearchPrint(arraySearch(array, 0, 19, 1));
	arraySearchPrint(arraySearch(array, 0, 19, 20));
	arraySearchPrint(arraySearch(array, 0, 19, 21));
	arraySearchPrint(arraySearch(array, 0, 19, 7));
	arraySearchPrint(arraySearch(array, 0, 19, 18));

	return shutdown();
}

int shutdown(){
	printf("\n\n");
	system("PAUSE");
}

int arraySearch(int* array, int left, int right, int value){
	int middle = (left + right) / 2;
	if (array[middle] == value){
		return middle;
	}
	if (left == right){
		return -1;
	}
	if (array[middle] < value){
		return arraySearch(array, middle + 1, right, value);
	}
	else{
		return arraySearch(array, left, middle - 1, value);
	}
}
void arraySearchPrint(int i)
{
	if (i > -1) printf("Hledane cislo se nachazi v poli s indexem %d.\n", i); else printf("Hledane cislo se v poli nenachazi.\n");
}