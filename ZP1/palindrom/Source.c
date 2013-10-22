#include <stdio.h>
int palindrom(char *retezec){
	int delka,i;
	for(delka=0;retezec[delka]!='\0';delka++);
	for(i=0;i<delka/2;i++){
		if(retezec[i]!=retezec[delka-i-1]){
			return 0;
		}
	}
	return 1;
}

void main(){
	char retezec[100];
	printf("Napis slovo: "); // maximalni delka slova je 99 znaku, pak to bude blbnout
	scanf("%s", retezec); // tady u promenne retezec neni &!
	printf("\nNapsal jsi: %s\n", retezec);

	printf("Toto slovo %s palindrom.",(palindrom(retezec))?"je":"neni");

	printf("\n\n");
	fflush(stdin);
	main();
}