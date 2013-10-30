#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int*, int);
void printArrayOFInt(int*, int);
int shutdown();
int restart();

int main(){
	int* pole;
	int delka;
	int i;

	printf("Kolik chcete vygenerovat nahodnych cisel?\n");
	scanf("%d", &delka);

	if (delka < 1){
		printf("Pocet nahodnych cisel musi byt vetsi nez nula.");
		return restart();
	}

	pole = (int*)malloc(sizeof(int)*delka);

	for (i = 0; i < delka; i++){
		pole[i] = rand() % 100;
	}

	printArrayOFInt(pole, delka);

	insertionSort(pole, delka);

	printArrayOFInt(pole, delka);

	return shutdown();
}
void insertionSort(int *pole, int n){
	int i, j, t;
	for (j = 1; j <= n - 1; j++){
		t = pole[j];
		i = j - 1;
		while (i >= 0 && pole[i] > t){
			pole[i + 1] = pole[i];
			i = i - 1;
		}
		pole[i + 1] = t;
	}
}

void printArrayOFInt(int *pole, int n){
	int i = 0;
	printf("\nArray print:\n");
	for (i = 0; i < n; i++){
		printf("%d ", pole[i]);
	}
	printf("\n");
}

int shutdown(){
	printf("\n\n");
	system("PAUSE");
	return 0;
}
int restart(){
	printf("\n\n");
	return main();
}