#include <stdio.h>
double prumer(int matice[][5], int pocet_radku){
	double prumer;
	int soucet=0;
	int pocet=0;
	int i,j;
	for(i=0;i<pocet_radku;i++){
		for(j=0;j<5;j++){
			soucet+=matice[i][j];
			pocet++;
		}
	}
	prumer = (double)soucet / pocet;
	return prumer;
}
void main(){
	int pole[][5] = {{1,2,-3,4,5},{6,1,45,12,0}};
	printf("Aritmeticky prumer cisel v matici je: %.2f.",prumer(pole,2));

	printf("\n\n");
	system("PAUSE");
}