#include <stdio.h>
#include <stdlib.h>
int* prirozena(int n){
	int* pole=(int*)malloc(sizeof(int) * n);
	int i;
	for(i=0;i<n;i++){
		pole[i]=i+1;
	}
	return pole;
}
void vypis_pole(int* pole,int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",pole[i]);
	}
}
void main(){
	int* jednociferna = prirozena(9);
	vypis_pole(jednociferna, 9); // 1 2 3 4 5 6 7 8 9

	printf("\n\n");
	system("PAUSE");
}