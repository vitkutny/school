#include <stdio.h>
int pocet;
int max(int cisla[]){
	int max=0,i;
	for(i=0;i<pocet;i++){
		if(cisla[i]>max){
			max = cisla[i];
		}
	}
	return max;
}
void main(){
	int cisla[10],i;
	printf("Pocet cisel: ");
	scanf("%d",&pocet);
	if(!(pocet>0 && pocet <=99999999)){
		printf("Pocet cisel musi byt v rozmezi 1-99999999.\n");
	}else{
		for(i=0;i<pocet;i++){
			printf("Zadejte cislo %d: ",i+1);
			scanf("%d",&cisla[i]);
		}
		printf("\nNejvetsi cislo je: %d\n\n",max(cisla));
	}
	fflush(stdin);
	main();
}