#include <stdio.h>
#include <stdlib.h>
void prirozena(int n, int** pole){
	int i;
	*pole=(int*) malloc(sizeof(int)*(n));
	for(i=0;i<n;i++){
		(*pole)[i]=i+1;
	}
}
void vypis_pole(int *pole, int delka){
	int i;
	for(i=0;i<delka;i++){
		printf("%d ",pole[i]);
	}
}
void main(){
	int* jednociferna;
	prirozena(10, &jednociferna);
	vypis_pole(jednociferna, 9); // 1 2 3 4 5 6 7 8 9

	printf("\n\n");
	system("PAUSE");
}