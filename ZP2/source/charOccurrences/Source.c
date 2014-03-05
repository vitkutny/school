#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* vyskyty(char**, int, char*);

int main(){
	int* v;
	int i;
	char* zdroj[10];
	char h[] = "nkazv";

	zdroj[0] = "Napiste";
	zdroj[1] = "funkci";
	zdroj[2] = "ktera";
	zdroj[3] = "vrati";
	zdroj[4] = "pocet";
	zdroj[5] = "vyskytu";
	zdroj[6] = "znaku";
	zdroj[7] = "v";
	zdroj[8] = "poli";
	zdroj[9] = "hledany.";
	v = vyskyty(zdroj, 10, h);
	for (i = 0; i < strlen(h); i++){
		printf("Znak %c se v poli texctovych retezcu vyskytuje %d.\n", h[i], v[i]);
	}

	system("PAUSE");
	return 0;
}

int* vyskyty(char* texty[], int pocet, char* hledany){
	int* vyskyty;
	int i, j, k;
	vyskyty = (int*)malloc(sizeof(int)* strlen(hledany));

	for (i = 0; i < strlen(hledany); i++){
		int v = 0;
		for (j = 0; j < pocet; j++){
			k = 0;
			while (texty[j][k] != '\0'){
				if (texty[j][k] == hledany[i]){
					v++;
				}
				k++;
			}
		}
		vyskyty[i] = v;
	}

	return vyskyty;
}