#ifndef _INC_ARRAY
#define _INC_ARRAY
typedef struct{
	int count; int* data;
} array;

array arrayCreate();
int arrayGet(array, int);
void arraySet(array*, int, int);
void arrayPush(array*, int);
int arrayPop(array*);
int arrayShift(array*);
#endif