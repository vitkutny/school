#include <stdio.h>
int podretez(char* a, char* b){
	int i,j,match;
	for(i=0;i<a[i]!='\0';i++){
		match = 1;
		for(j=0;j<b[j]!='\0';j++){
			if(a[i+j]!=b[j]){
				match = 0;
				break;
			}
		}
		if(match){
			return i;
		}
	}
	return -1;
}

void main(){
	char* a ="ahoj jak se mas";
	char* b ="se mas";


	printf("Slovo '%s' je ve vete '%s' na indexu %d\n",b,a,podretez(a,b));

	system("PAUSE");
}