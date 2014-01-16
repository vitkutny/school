#include <stdio.h>
#include <stdlib.h>
double na2(double x){
	return x*x;
}

double na3(double x){
	return x*x*x;
}
void vypis_pole(double* pole,int delka){
	int i;
	for(i=0;i<delka;i++){
		printf("%g\t",pole[i]);
	}
	printf("\n");
}

double* map(double (*funkce)(double),double* vstup,int delka){
	int i;
	double* pole=(double*)malloc(sizeof(double)*delka);
	for(i=0;i<delka;i++){
		pole[i]=funkce(vstup[i]);
	}
	return pole;
}

int main(){
	double vstup[]={1,2,3,4,5};
	double* pole_vysledku_na2;
	double* pole_vysledku_na3;

	pole_vysledku_na2 = map(na2, vstup,5);
	pole_vysledku_na3 = map(na3, vstup,5);

	printf("Vstupni pole:\n");vypis_pole(vstup,5);
	printf("Druhe mocniny:\n");vypis_pole(pole_vysledku_na2,5);
	printf("Treti mocniny:\n");vypis_pole(pole_vysledku_na3,5);

	printf("\n\n");
	system("PAUSE");
}