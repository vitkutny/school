#include <stdio.h>
#include "canvas.h"

int shutdown();

int main(){
	canvas* canvas;
	canvas = canvas_create(10, 10);
	canvas_draw_rect(canvas, 0, 0, 5, 5, '<');
	canvas_draw_rect(canvas, 5, 5, 5, 5, '>');
	canvas_print(canvas);

	return shutdown();
}

int shutdown(){
	printf("\n\n");
	system("PAUSE");
	return 0;
}