#include <stdio.h>
void inkrementuj(int *cislo){
	*cislo+=1;
}
void main(){
	int cislo = 4;

	inkrementuj(&cislo);

	printf("%d\n\n",cislo);
	system("PAUSE");
}