#include <stdlib.h>
#include "array.h"

array arrayCreate(){
	array array;
	array.count = 0;
	array.data = (int*)malloc(NULL);
	return array;
}

int arrayGet(array array, int index){
	if (index < array.count){
		return array.data[index];
	}
	return NULL;
}

void arraySet(array* array, int index, int value){
	if (index < array->count){
		array->data[index] = value;
	}
}

void arrayPush(array* array, int value){
	array->count += 1;
	array->data = (int*)realloc(array->data, (array->count)*sizeof(int));
	arraySet(array, array->count - 1, value);
}

int arrayPop(array* array){
	int value;
	if (array->count){
		value = arrayGet(*array, array->count - 1);
		array->count -= 1;
		array->data = (int*)realloc(array->data, (array->count)*sizeof(int));
		return value;
	}
	return NULL;
}

int arrayShift(array* array){
	int value;
	int i;
	if (array->count){
		value = arrayGet(*array, 0);
		for (i = 0; i < array->count - 1; i++){
			arraySet(array, i, arrayGet(*array, i + 1));
		}
		array->count -= 1;
		array->data = (int*)realloc(array->data, array->count*sizeof(int));
		return value;
	}
	return NULL;
}