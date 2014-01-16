#include <stdio.h>
#include <stdlib.h>

void main(){
	int* cisla;
	int i,j,n;

	printf("Vypsat prvocisla po cislo: ");
	scanf("%d",&n);
	printf("\n");
	n-=1;
	cisla = (int*)malloc(sizeof(int)*n);

	for(i=0;i<n;i++){
		cisla[i]=i+2;
	}

	for(i=0;i<n;i++){
		if(cisla[i]){
			printf("%d ",cisla[i]);
		}
		for(j=i+1;j<n;j++){
			if(cisla[i] && cisla[j] % cisla[i]==0){
				cisla[j]=0;
			}
		}
	}

	printf("\n\n");
	fflush(stdin);
	main();
}