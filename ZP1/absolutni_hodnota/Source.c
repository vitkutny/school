#include <stdio.h>
void main(){
	int cislo;
	int abs;
	printf("Zadejte cislo: ");
	scanf("%d",&cislo);
	abs = cislo;
	if(abs<0) abs*=-1;
	printf("Absolutni hodnota cisla %d je %d\n\n",cislo,abs);

	fflush(stdin);
	main();
}