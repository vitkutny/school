#include <stdio.h>
#include <stdlib.h>

int shutdown();
int restart();
int deleni(int, int, int*);

int main(){
	int a, b, vysledek, zbytek;
	system("CLS");
	printf("Vydel cislo: ");
	scanf("%i", &a);
	printf("Cislem: ");
	scanf("%i", &b);
	if (!b){
		printf("\nNelze delit cislem nula.");
		return shutdown();
	}
	vysledek = deleni(a, b, &zbytek);
	printf("\nVysledek deleni cisla %i cislem %i je: %i zbytek %i", a, b, vysledek, zbytek);
	return restart();
}

int shutdown(){
	printf("\n\n");
	system("PAUSE");
	return 0;
}

int restart(){
	printf("\n\n");
	system("PAUSE");
	return main();
}

int deleni(int a, int b, int* zbytek){
	int vysledek = 0;
	while (a >= b){
		a -= b;
		vysledek++;
	}
	*zbytek = a;
	return vysledek;
}