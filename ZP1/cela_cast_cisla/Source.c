#include <stdio.h>
void main(){
	float cislo;
	int cele;
	printf("Zadejte cislo: ");
	scanf("%f",&cislo);
	cele = (int) cislo;
	printf("Cela cast cisla %.2f je %d\n\n",cislo,cele);
	fflush(stdin);
	main();
}