#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int male_pismeno(char a){
	if(a>='a' && a<='z'){
		return 1;
	}else{
		return 0;
	}
}
int velke_pismeno(char a){
	if(a>='A' && a<='Z'){
		return 1;
	}else{
		return 0;
	}
}
char* odstran_ze_zacatku(int (*predikat)(char), const char* retezec){
	int i,j;
	char* novy;
	int delka = strlen(retezec);
	for(i=0;i<delka;i++){
		if(predikat(retezec[i])){
		}else{
			break;
		}
	}
	novy = (char*)malloc(sizeof(char)*(delka+1));
	for(j=0;j<delka-i;j++){
		novy[j]=retezec[j+i];
	}
	novy[j]='\0';
	return novy;

}
void main(){
	printf("%s\n", odstran_ze_zacatku(male_pismeno, "abcDEF")); // DEF
	printf("%s\n", odstran_ze_zacatku(male_pismeno, "ABCdef")); // ABCdef
	printf("%s\n", odstran_ze_zacatku(male_pismeno, "abcDEFghij")); // DEFghij
	printf("%s\n", odstran_ze_zacatku(male_pismeno, "baba nebo snih")); //  nebo snih

	printf("%s\n", odstran_ze_zacatku(velke_pismeno, "abcDEF")); // abcDEF
	printf("%s\n", odstran_ze_zacatku(velke_pismeno, "ABCdef")); // def
	printf("%s\n", odstran_ze_zacatku(velke_pismeno, "abcDEFghij")); // abcDEFghij
	printf("%s\n", odstran_ze_zacatku(velke_pismeno, "baba nebo snih")); // baba nebo snih
	printf("%s\n", odstran_ze_zacatku(velke_pismeno, "baba")); // baba
	printf("\n\n");
	system("PAUSE");
}