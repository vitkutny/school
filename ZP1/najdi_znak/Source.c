#include <stdio.h>
int najdi_znak(char retezec[], char znak, int n){
	int index = -1;
	int vyskyt = 0;
	int i=0;

	while(1){
		if(retezec[i] == '\0'){
			break;
		}

		if(retezec[i] == znak){
			vyskyt++;
			if(vyskyt == n){
				index = i;
				break;
			}
		}

		i++;
	}

	return index;
}
void main(){
	printf("Index: %i\n", najdi_znak("sekera sobota taxi", 's', 1)); // Index: 0 
	printf("Index: %i\n", najdi_znak("sekera sobota taxi", 's', 2)); // Index: 7
	printf("Index: %i\n", najdi_znak("sekera sobota taxi", 'x', 1)); // Index: 16
	printf("Index: %i\n", najdi_znak("sekera sobota taxi", 'x', 2)); // Index: -1
	printf("Index: %i\n", najdi_znak("sekera sobota taxi", 'a', 3)); // Index: 15 
	printf("Index: %i\n", najdi_znak("sekera sobota taxi", '!', 3)); // Index: -1

	printf("\n\n");
	system("PAUSE");
}