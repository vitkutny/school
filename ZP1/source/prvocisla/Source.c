#include <stdio.h>
void main(){
	int i,j,prvocislo,max;
	printf("Vypsat prvocisla po cislo:\n");
	scanf("%d",&max);

	for(i=2;i<=max;i++){
		prvocislo=1;
		for(j=2;j<i;j++){
			if(i%j == 0){
				prvocislo = 0;
			}
		}
		if(prvocislo == 1){
			printf("%d ",i);
		}
	}
	printf("\n\n");
	fflush(stdin);
	main();
}