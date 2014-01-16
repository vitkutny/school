#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void set(char *vstup,char **vystup){
	int delka = strlen(vstup),i,j;
	*vystup = (char*) malloc(sizeof(char)*(delka+1));
	for(i=0;i<delka;i++){
		j=0;
		if(vstup[i]>=65 && vstup[i]<=90){ //A-Z
			j+=32;
		}else if(vstup[i]>=97 && vstup[i]<=122){ //a-z
			j-=32;
		}
		(*vystup)[i]=vstup[i]+j;
	}
	(*vystup)[i]='\0';
}
void main(){
	char* vstup = "Ahoj svete 23.";
	char* vystup;
	set(vstup, &vystup);
	printf("a - %d, A - %d\n\n",'a','A');
	printf("z - %d, Z - %d\n\n",'z','Z');
	printf("%s\n", vystup);

	printf("\n\n");
	system("PAUSE");
}