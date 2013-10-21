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
	//Vytvoøíme pole všech èísel od 2 do požadovaného maximálního zkoumaného èísla.
	for(i=2;i<=MAX;i++){
		pole[i-2]=i;
	}
	printf("Vstupni pole:\n");
	printArray(pole);
	printf("\n\n");
	printf("Prvocisla:\n");

	//Procházíme pole od zaèátku, dokud nenajdeme nevyškrtnuté èíslo. Toto èíslo je prvoèíslem, mùžeme jej proto vypsat na obrazovku.
	for(i=0;i<=MAX-2;i++){
		if(pole[i]!=0){
			printf("%d ",pole[i]);
			//Vyškrtáme z pole všechny násobky právì nalezeného prvoèísla (napø. zmìnou hodnoty na 0).
			for(j=0;j<=MAX-2;j++){
				if((pole[j]!=0)&&(pole[j]!=pole[i])&&(pole[j] % pole[i] == 0)){
					pole[j]=0;
				}
			}
		}
	} //Pokraèujeme krokem 2, dokud zbývají nìjaká nevyškrtnutá èísla.

	printf("\n\n");
	system("PAUSE");
}