#include <stdio.h>
#include <stdlib.h>

typedef struct s{
	int rows; int cols; int length; int* data;
} bitmap;

int shutdown();
int restart();
bitmap bitmap_create(int, int);
void bitmap_print(bitmap*);
void bitmap_from_array(bitmap*, int**, int, int);
void bitmap_copy(bitmap*, bitmap*);
void bitmap_inverse(bitmap*);
void bitmap_or(bitmap*, bitmap*, bitmap*);
void bitmap_and(bitmap*, bitmap*, bitmap*);

int main(){
	int plus_array[][5] = {
		{ 0, 0, 1, 0, 0 },
		{ 0, 0, 1, 0, 0 },
		{ 1, 1, 1, 1, 1 },
		{ 0, 0, 1, 0, 0 },
		{ 0, 0, 1, 0, 0 }
	};
	int box_array[][5] = {
		{ 1, 1, 1, 1, 1 },
		{ 1, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 1 },
		{ 1, 1, 1, 1, 1 }
	};
	bitmap first = bitmap_create(5, 5);
	bitmap second = bitmap_create(5, 5);
	bitmap third = bitmap_create(5, 5);

	bitmap_from_array(&first, plus_array, 5, 5);
	bitmap_from_array(&second, box_array, 5, 5);

	bitmap_or(&third, &first, &second);

	bitmap_print(&first);
	bitmap_print(&second);
	bitmap_print(&third);

	return shutdown();
}

int shutdown(){
	printf("\n\n");
	system("PAUSE");
	return 0;
}
int restart(){
	system("cls");
	return main();
}
bitmap bitmap_create(int rows, int cols){
	bitmap bm;
	bm.rows = rows;
	bm.cols = cols;
	bm.length = rows*cols;
	bm.data = (int*)malloc(sizeof(int)*bm.length);
	return bm;
}
void bitmap_print(bitmap* bm){
	int i, j;
	printf("\n");
	for (i = 0; i < bm->rows; i++){
		for (j = 0; j < bm->cols; j++){
			printf("%i", bm->data[(i*bm->cols) + j]);
		}
		printf("\n");
	}
}
void bitmap_from_array(bitmap* bm, int** array, int rows, int cols){
	int i;
	for (i = 0; i < bm->length; i++){
		bm->data[i] = array[i];
	}
}
void bitmap_copy(bitmap* target, bitmap* source){
	bitmap_from_array(target, source->data, source->rows, source->cols);
}
void bitmap_inverse(bitmap* bm){
	int i;
	for (i = 0; i < bm->length; i++){
		bm->data[i] = (bm->data[i]) ? 0 : 1;
	}
}
void bitmap_or(bitmap* target, bitmap* first, bitmap* second){
	int i;
	int* or;
	or = (int*)malloc(sizeof(int)*first->length);

	for (i = 0; i < first->length; i++){
		or[i] = (first->data[i] || second->data[i]) ? 1 : 0;
	}

	bitmap_from_array(target, or, first->rows, first->cols);
}
void bitmap_and(bitmap* target, bitmap* first, bitmap* second){
	int i;
	int* and;
	and = (int*)malloc(sizeof(int)*first->length);

	for (i = 0; i < first->length; i++){
		and[i] = (first->data[i] && second->data[i]) ? 1 : 0;
	}

	bitmap_from_array(target, and, first->rows, first->cols);
}