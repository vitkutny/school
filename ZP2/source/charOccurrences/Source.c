#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* charOccurrences(char**, int, char*);

int main(){
	int* occurrences;
	char* input[10];
	char string[] = "nkazv";
	int i;

	input[0] = "Napiste";
	input[1] = "funkci";
	input[2] = "ktera";
	input[3] = "vrati";
	input[4] = "pocet";
	input[5] = "vyskytu";
	input[6] = "znaku";
	input[7] = "v";
	input[8] = "poli";
	input[9] = "hledany.";
	occurrences = charOccurrences(input, 10, string);
	for (i = 0; i < strlen(string); i++){
		printf("Znak %c se v poli texctovych retezcu vyskytuje %d.\n", string[i], occurrences[i]);
	}

	system("PAUSE");
	return 0;
}

int* charOccurrences(char* input[], int count, char* string){
	int* occurrences;
	int i, j, k, charCount;
	occurrences = (int*)malloc(sizeof(int)* strlen(string));

	for (i = 0; i < strlen(string); i++){
		charCount = 0;
		for (j = 0; j < count; j++){
			k = 0;
			while (input[j][k] != '\0'){
				if (input[j][k] == string[i]){
					charCount++;
				}
				k++;
			}
		}
		occurrences[i] = charCount;
	}

	return occurrences;
}