#include <stdio.h>
int maximum_pole(int cisla[],int delka_pole){
	int max=cisla[0],i;
	for(i=0;i<delka_pole;i++){
		if(cisla[i]>max){
			max = cisla[i];
		}
	}
	return max;
}
void main(){
	int pole[] = {-4, -6, -1, -9, -2};
	printf("Nejvetsi cislo: %i", maximum_pole(pole, 5));
	printf("\n\n");
	system("PAUSE");
}