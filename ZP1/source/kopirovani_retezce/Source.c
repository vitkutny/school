#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* kopiruj(char* retezec){
	char* kopie=(char*)malloc(sizeof(retezec));
	int i;
	for(i=0;i<=strlen(retezec);i++){
		kopie[i] = retezec[i];
	}
	return kopie;
}
void main(){
	char pozdrav[] = "ahoj";
	char* kopie = kopiruj(pozdrav);
	pozdrav[0] = '!';
	printf("%s, %s\n", pozdrav, kopie); // !hoj, ahoj

	printf("\n\n");
	system("PAUSE");
}