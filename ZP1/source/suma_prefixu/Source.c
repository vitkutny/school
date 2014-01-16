#include <stdio.h>
#define MAX 5
void printArray(int pole[]){
	int i;
	for(i=0;i<MAX;i++){
		printf("%d ",pole[i]);
	}
}
void main(){
	int pole[MAX]={1,2,3,5,8};
	int i,j,soucet;

	printf("Vstupni pole:\n");
	printArray(pole);
	for(i=MAX-1;i>=0;i--){
		soucet = 0;
		for(j=i;j>=0;j--){
			soucet+=pole[j];
		}
		pole[i] = soucet;
	}
	printf("\nSuma prefixu tohoto pole:\n");
	printArray(pole);
	printf("\n\n");
	system("PAUSE");
}