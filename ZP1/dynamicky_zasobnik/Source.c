#include <stdio.h>
#include <stdlib.h>
typedef struct prvek{
	int data;struct prvek *before;
} prvek;
prvek *pridej(prvek* zasobnik, int data){
	prvek *novy=(prvek *) malloc(sizeof(prvek));
	novy->data = data;
	novy->before = zasobnik;
	zasobnik = novy;
	return zasobnik;
}
int vrchol(prvek* zasobnik){
	if(zasobnik!=NULL){
		return (*zasobnik).data;
	}
}
prvek* odeber(prvek* zasobnik){
	if(zasobnik != NULL){
		prvek *novy = zasobnik;
		zasobnik = zasobnik->before;
		free(novy);
	}
	return zasobnik;
}
int main(){
	prvek* test = NULL;
	prvek* z = NULL;
	prvek* milion = NULL;
	int i;


	// PRVNI TEST
	// Symbol [ reprezentuje dno zasobniku
	test = pridej(test, 5);                     // zasobnik vypada takto: [ 5
	printf("prvni: %i\n", vrchol(test));        // 5
	test = pridej(test, 14);                    // zasobnik vypada takto: [ 5 14
	printf("druhy: %i\n", vrchol(test));        // 14
	test = odeber(test);                        // zasobnik vypada takto: [ 5
	printf("opet prvni: %i\n", vrchol(test));   // 5
	test = odeber(test);                        // zasobnik je prazdny: [



	// DRUHY TEST
	for (i = 1; i < 11; i++)
		z = pridej(z, i);

	while (z != NULL){
		printf("%i ", vrchol(z));
		z = odeber(z);
	} // Vypise: 10 9 8 7 6 5 4 3 2 1 



	// TRETI TEST
	for (i = 1; i < 1000000; i++) 
		milion = pridej(milion, i);

	for (i = 1; i < 1000000 - 1; i++)
		milion = odeber(milion);

	printf("\nmilion: %i\n", vrchol(milion));   // milion: 1

	return 0;
}