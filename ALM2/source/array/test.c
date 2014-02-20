#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int shutdown();

int main()
{
	array array;
	int i;
	array = arrayCreate();

	printf("Zasobnik:\n");
	arrayPush(&array, 5);
	arrayPush(&array, 2);
	arrayPush(&array, 4);
	printf("%d\n", arrayPop(&array));
	printf("%d\n", arrayPop(&array));
	arrayPush(&array, 3);
	arrayPush(&array, 7);
	arrayPush(&array, 9);
	for (i = array.count - 1; i >= 0; i--){
		printf("%d\n", arrayPop(&array));
	}

	printf("\nFronta:\n");
	arrayPush(&array, 5);
	arrayPush(&array, 2);
	arrayPush(&array, 4);
	printf("%d\n", arrayShift(&array));
	printf("%d\n", arrayShift(&array));
	arrayPush(&array, 3);
	arrayPush(&array, 7);
	arrayPush(&array, 9);
	for (i = array.count - 1; i >= 0; i--){
		printf("%d\n", arrayShift(&array));
	}

	return shutdown();
}

int shutdown(){
	printf("\n\n");
	system("PAUSE");
}