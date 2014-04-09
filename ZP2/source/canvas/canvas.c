#include <stdlib.h>
#include "canvas.h"

canvas* canvas_create(int width, int height){
	int i, j;
	canvas* new;
	new = (canvas*)malloc(sizeof(canvas));
	new->width = width;
	new->height = width;
	new->pixels = (char**)malloc(sizeof(char*)* height);
	for (i = 0; i < height; i++){
		new->pixels[i] = (char*)malloc(sizeof(char)*width);
	}
	canvas_clear(new);
	return new;
}

void canvas_draw_rect(canvas* canvas, int x, int y, int width, int height, char pixel){
	int i, j;
	for (i = 0; i < canvas->height; i++){
		for (j = 0; j < canvas->width; j++){
			if ((j >= x && j + 1 <= x + width) && (i >= y && i + 1 <= y + height)){
				canvas->pixels[i][j] = pixel;
			}
		}
	}
}

void canvas_clear(canvas* canvas){
	int i, j;
	for (i = 0; i < canvas->height; i++){
		for (j = 0; j < canvas->width; j++){
			canvas->pixels[i][j] = '.';
		}
	}
}

void canvas_print(canvas* canvas){
	int i, j;
	for (i = 0; i < canvas->height; i++){
		for (j = 0; j < canvas->width; j++){
			printf("%c", canvas->pixels[i][j]);
		}
		printf("\n");
	}
}