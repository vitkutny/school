#include <stdio.h>
double prumer_pole(int *pole,int delka){
	int i;
	int soucet=0;
	for(i=0;i<delka;i++){
		soucet+=pole[i];
	}
	return (double) soucet/i;
}
void vypis_pole(int *pole,int delka){
	int i;
	printf("\nVypis pole:\n");
	for(i=0;i<delka;i++){
		printf("%d ",pole[i]);
	}
	printf("\n");
}
void main(){
	int pole[]={1,2,3,4,5,6};
	int delka = 6;
	vypis_pole(pole,delka);
	printf("Prumer pole: %g",prumer_pole(pole,delka));

	printf("\n\n");
	system("PAUSE");
}