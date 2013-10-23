#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* zretezeni(char* a, char*b, char** c){
	int i;
	int j;
	(*c)=(char*)malloc(sizeof(char)*(strlen(a)+strlen(b)));
	for (i=0;a[i]!='.';i++){
		(*c)[i]=a[i];
	}
	for(j=0;b[j]!='.';j++,i++){
		(*c)[i]=b[j];
	}
	(*c)[i]='.';
	(*c)[i+1]='\0';
}

void main(){
	char* a ="abcd.";
	char* b ="xyz.";
	char* c;
	zretezeni(a,b,&c);

	printf("%s\n\n",c);

	system("PAUSE");
}