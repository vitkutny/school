#include <stdio.h>
void obrat_pole(int pole[], int delka){
	int i,temp;
	for (i=0;i<delka/2;i++){
		temp = pole[i];
		pole[i]=pole[delka-1-i];
		pole[delka-1-i]=temp;
	}
}
void vypis_pole(int pole[], int delka){
	int i;
	printf("Vypis pole:\n");
	for(i=0;i<delka;i++){
		printf("%d ",pole[i]);
	}
	printf("\n\n");
}
void main(){
	int pole1[] = {1, 2, 3, 4, 5};
	int pole2[] = {1, 2, 3, 4, 5, 6};
	int pole3[] = {13};
	int delka1 = 5, delka2 = 6, delka3 = 1;

	obrat_pole(pole1, delka1);
	vypis_pole(pole1, delka1);

	obrat_pole(pole2, delka2);
	vypis_pole(pole2, delka2);

	obrat_pole(pole3, delka3);
	vypis_pole(pole3, delka3);

	system("PAUSE");
}