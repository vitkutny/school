#include <stdio.h>
#include <stdlib.h>
#include "charCount.h"

int charCountInFile(char* input_file, char* output_file, char* letters){
	FILE* input;
	FILE* output;
	char letter;
	char* file_letters;
	int file_letters_count = 0;
	int count;
	int i, j;
	input = fopen(input_file, "r");
	if (!input){
		return 0;
	}
	file_letters = (char*)malloc(NULL);
	do{
		letter = (char)getc(input);
		file_letters_count++;
		file_letters = (char*)realloc(file_letters, sizeof(char)*file_letters_count);
		file_letters[file_letters_count - 1] = letter;
	} while (letter != EOF);
	fclose(input);
	output = fopen(output_file, "w");
	if (!output){
		return 0;
	}
	for (i = 0; i < strlen(letters); i++){
		count = 0;
		for (j = 0; j < file_letters_count; j++){
			if (file_letters[j] == letters[i]){
				count++;
			}
		}
		fprintf(output, "%c - %d\n", letters[i], count);
	}
	fclose(output);
	return 1;
}