#include <stdio.h>
char *smaz_mezery(char *retezec){
	int i=0;
	while(retezec[i]==' '){
		i++;
	}
	if(retezec[i]=='\0'){
		return NULL;
	}
	return retezec+i;
}
void main(){
	printf("%s\n", smaz_mezery("    ahoj"));  // ahoj
	printf("%s\n",smaz_mezery("   ")); // vraci (null)
	printf("%s\n", smaz_mezery("ahoj")); // ahoj

	system("PAUSE");
}