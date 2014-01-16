#include <stdio.h>
void main(){
	int cislo,i;
	printf("\nZadejte cislo: ");
	scanf("%d",&cislo);
	printf("Mala nasobilka zadaneho cisla:\n");
	for(i=1;i<=10;i++){
		printf("%d ",i*cislo);
	}
	fflush(stdin);
	main();
}