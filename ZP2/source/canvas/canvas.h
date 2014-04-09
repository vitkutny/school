#ifndef _INC_CANVAS
#define _INC_CANVAS
typedef struct canvas{
	int width; int height; char** pixels;
} canvas;

canvas* canvas_create(int, int);
void canvas_draw_rect(canvas*, int, int, int, int, char);
void canvas_clear(canvas*);
void canvas_print(canvas*);
#endif