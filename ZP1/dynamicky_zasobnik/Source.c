#include <stdio.h>
#include <stdlib.h>

typedef struct s {
	int data; struct s* prev;
} prvek;

int shutdown();
prvek* pridej(prvek*, int);
int vrchol(prvek*);
prvek* odeber(prvek*);

int main(){
	prvek* zasobnik = (prvek*)malloc(sizeof(prvek));
	zasobnik->data = NULL;
	zasobnik->prev = NULL;

	zasobnik = pridej(zasobnik, 10);
	zasobnik = pridej(zasobnik, 20);
	zasobnik = odeber(zasobnik);

	printf("%i\n", vrchol(zasobnik));

	return shutdown();
}
int shutdown(){
	printf("\n\n");
	system("PAUSE");
	return 0;
}
prvek* pridej(prvek* zasobnik, int data){
	prvek* novy;
	novy = (prvek*)malloc(sizeof(prvek));
	novy->data = data;
	novy->prev = zasobnik;
	return novy;
}
int vrchol(prvek* zasobnik){
	return zasobnik->data;
}
prvek* odeber(prvek* zasobnik){
	prvek* prev;
	if (zasobnik->prev != NULL){
		prev = zasobnik->prev;
		free(zasobnik);
		return prev;
	}
	return zasobnik;
}