#include <stdio.h>
#include <stdlib.h>

int shutdown();
void vypis_pole(int*, int);
int mincovka(unsigned int, unsigned int**);

int main(){
	int* platidla;
	int pocet;
	int castka = 12345;

	pocet = mincovka(castka, &platidla);

	printf("castka: %d\n", castka);
	printf("pouzite platidla (%d): ", pocet);
	vypis_pole(platidla, pocet);

	return shutdown();
}

int shutdown(){
	printf("\n\n");
	system("PAUSE");
	return 0;
}

void vypis_pole(int* pole, int delka){
	int i;
	for (i = 0; i < delka; i++){
		if (i){
			printf(", %d", pole[i]);
		}
		else{
			printf("%d", pole[i]);
		}
	}
	printf("\n");
}

int mincovka(unsigned int castka, unsigned int **platidla){
	int i = 0, j;
	int bankovky[] = { 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5, 2, 1 };
	*platidla = (int*)malloc(NULL);

	while (castka){
		j = 0;
		while (castka < bankovky[j]){ j++; }

		castka -= bankovky[j];
		*platidla = (int*)realloc(*platidla, sizeof(int)*(i + 1));
		(*platidla)[i] = bankovky[j];

		i++;
	}

	return i;
}