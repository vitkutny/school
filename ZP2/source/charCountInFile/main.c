#include "charCount.h"

int main(int arguments_count, char* arguments[]){
	int i;
	char* input_file = "input.txt";
	char* output_file = "output.txt";
	char* letters = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";

	if (arguments_count == 4){
		input_file = arguments[1];
		output_file = arguments[2];
		letters = arguments[3];
	}

	return charCountInFile(input_file, output_file, letters);
}