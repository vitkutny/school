#include <stdio.h>
#include <math.h>
#include "calculations.h"

void square(long double a){
	long double perimeter = a * 4;
	long double area = a * a;
	printf("Square:\n");
	printf("\tPerimeter: %g\n", perimeter);
	printf("\tArea: %g\n", area);
}

void triangle(long double a, long double b, long double c){
	long double perimeter, area, p;
	perimeter = a + b + c;
	p = perimeter / 2;
	area = sqrt(p*(p - a)*(p - b)*(p - c)); //heron's formula
	printf("Triangle:\n");
	printf("\tPerimeter: %g\n", perimeter);
	printf("\tArea: %g\n", area);
}