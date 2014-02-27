#include <stdio.h>
#include <string.h>
#include "Jmena.h"

void arraySearchString(char**, int);
void bubbleSort(char**, int);
void swap(char*, char*);
int shutdown();

int main(){
	int i;
	int length;
	length = sizeof(Jmena) / sizeof(*Jmena);

	bubbleSort(Jmena, length);

	printf("Pro ukonceni programu zadejte misto jmena 'exit'.\n\n");
	arraySearchString(Jmena, length);
}

void arraySearchString(char** array, int length){
	char* jmeno[100];
	int i = 0;
	int found = 0;

	printf("Zadej jmeno: ");
	scanf("%s", jmeno);
	fflush(stdin);

	if (strcmp(jmeno, "exit") == 0){
		printf("Nashledanou.");
		return shutdown();
	}

	for (i = 0; i < length; i++){
		if (strcmp(array[i], jmeno) == 0){
			found = 1;
			break;
		}
	}

	if (found){
		printf("Jmeno %s bylo nalezeno na pozici %d.", jmeno, i);
	}
	else{
		printf("Jmeno %s nebylo nalezeno.", jmeno);
	}

	printf("\n\n");
	arraySearchString(array, length);
}

void bubbleSort(char** array, int length){
	int i, j;
	for (i = 0; i < length - 1; i++){
		for (j = 0; j < length - i - 1; j++){
			if (strcmp(array[j + 1], array[j]) == -1){
				swap(&array[j], &array[j + 1]);
			}
		}
	}
}

void swap(char** a, char** b){
	char* temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int shutdown(){
	printf("\n\n");
	system("PAUSE");
	return 0;
}