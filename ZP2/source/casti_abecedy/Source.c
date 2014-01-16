#include <stdio.h>
#include <stdlib.h>

char** casti_abecedy(int* delky, int pocet){
	int i,j;
	char** casti = (char **) malloc(sizeof(char*)*pocet);
	for(i=0;i<pocet;i++){
		casti[i]=(char *) malloc(sizeof(char)*(delky[i]+1));
		for(j=0;j<delky[i];j++){
			casti[i][j]=97+j;
		}
		casti[i][j]='\0';
	}
	return casti;
}
void main(){
	int delky[] = {2, 5, 7, 1};
	char** casti = casti_abecedy(delky, 4);
	int i;
	for (i = 0; i < 4; i++) 
		printf("%s\n", casti[i]);
	// Vystup by vypadal takto:
	// ab
	// abcde
	// abcdefg
	// a

	printf("\n\n");
	system("PAUSE");
}