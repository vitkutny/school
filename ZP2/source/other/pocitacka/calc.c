#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculations.h"

int main(int argc, char* argv[]){
	int i;
	int result;
	if (argc < 2){
		printf("Help:\n");
		printf("-s <size> - perimeter and area of square\n");
		printf("-t <a> <b> <c> - perimeter and area of triangle\n");
		printf("<number> <+|-|*> <number> <+|-|*> <number> ...\n");
		return 0;
	}
	if (strlen(argv[1]) == 2 && argv[1][0] == '-'){
		switch (argv[1][1]){
		case 's':
			if (argc >= 3){
				square((long double)atof(argv[2]));
				return 0;
			}
			break;
		case 't':
			if (argc >= 5){
				triangle((long double)atof(argv[2]), (long double)atof(argv[3]), (long double)atof(argv[4]));
				return 0;
			}
			break;
		}
	}
	result = atoi(argv[1]);
	for (i = 2; i < argc; i++){
		if (argv[i][0] == '+' && i + 1 < argc){
			result += atoi(argv[i + 1]);
		}
		else if (argv[i][0] == '-'){
			result -= atoi(argv[i + 1]);
		}
		else if (argv[i][0] == '*'){
			result *= atoi(argv[i + 1]);
		}
	}
	printf("Result: %d\n", result);
	return 0;
}