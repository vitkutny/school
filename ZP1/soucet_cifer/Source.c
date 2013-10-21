#include <stdio.h>
int soucet_cifer(int cislo){
	int soucet=0;
	while(cislo > 0){
		soucet += cislo % 10;
		cislo /= 10;
	}
	return soucet;
}
void main (){
	int cislo;
	printf("Zadejte cislo: ");
	scanf("%i",&cislo);
	printf("Soucet cifer cisla %d je: %d\n\n",cislo,soucet_cifer(cislo));
	fflush(stdin);
	main();
}