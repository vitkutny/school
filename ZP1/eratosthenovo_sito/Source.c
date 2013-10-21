#include <stdio.h>
#define MAX 100
void printArray(int pole[]){
	int i;
	for(i=0;i<MAX-1;i++){
		printf("%d ",pole[i]);
	}
}
void main(){
	int pole[MAX-1];
	int i,j;
	//Vytvo��me pole v�ech ��sel od 2 do po�adovan�ho maxim�ln�ho zkouman�ho ��sla.
	for(i=2;i<=MAX;i++){
		pole[i-2]=i;
	}
	printf("Vstupni pole:\n");
	printArray(pole);
	printf("\n\n");
	printf("Prvocisla:\n");

	//Proch�z�me pole od za��tku, dokud nenajdeme nevy�krtnut� ��slo. Toto ��slo je prvo��slem, m��eme jej proto vypsat na obrazovku.
	for(i=0;i<=MAX-2;i++){
		if(pole[i]!=0){
			printf("%d ",pole[i]);
			//Vy�krt�me z pole v�echny n�sobky pr�v� nalezen�ho prvo��sla (nap�. zm�nou hodnoty na 0).
			for(j=0;j<=MAX-2;j++){
				if((pole[j]!=0)&&(pole[j]!=pole[i])&&(pole[j] % pole[i] == 0)){
					pole[j]=0;
				}
			}
		}
	} //Pokra�ujeme krokem 2, dokud zb�vaj� n�jak� nevy�krtnut� ��sla.

	printf("\n\n");
	system("PAUSE");
}