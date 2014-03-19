#include <stdio.h>
#include <stdarg.h>

typedef struct{
	double real; double imaginary;
} complex;

complex complexSum(int, ...);

int main(){
	complex result;
	complex first = { 3.1, -2.3 };
	complex second = { 0.5, -3 };
	complex third = { 0, 1.2 };

	result = complexSum(3, first, second, third);
	printf("Result: %g + %gi.", result.real, result.imaginary);

	printf("\n\n");
	system("PAUSE");
	return 0;
}

complex complexSum(int count, ...){
	complex number;
	complex result = { 0, 0 };

	va_list params;
	va_start(params, count);

	while (count > 0){
		number = va_arg(params, complex);
		result.real += number.real;
		result.imaginary += number.imaginary;
		count--;
	}

	va_end(params);
	return result;
}