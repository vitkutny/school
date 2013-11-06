#include <stdio.h>

int restart();
int shutdown();
int do_desitkove(char*, int);
int string_length(char*);
int mocnina(int, int);

int main(){
	printf("%i\n", do_desitkove("A1B", 12));
	printf("%i\n", do_desitkove("1010", 2));
	printf("%i\n", do_desitkove("0010", 2));
	return shutdown();
}

int do_desitkove(char* cisla, int zaklad){
	int i;
	int soucet = 0;
	int cislo;
	int delka = string_length(cisla);
	int exponent = delka;
	for (i = 0; i < delka; i++){
		exponent--;
		if (cisla[i] >= '0' && cisla[i] <= '9'){
			cislo = (int)cisla[i] - 48;
		}
		else if (cisla[i] >= 'A' && cisla[i] <= 'Z'){
			cislo = (int)cisla[i] - 55;
		}
		soucet += cislo*mocnina(zaklad, exponent);
	}
	return soucet;
}
int mocnina(int cislo, int exponent){
	int i;
	int soucet = 1;
	if (!cislo && !exponent){
		return 0;
	}
	for (i = 1; i <= exponent; i++){
		soucet *= cislo;
	}
	return soucet;
}
int string_length(char* str){
	int i = 0;
	while (str[i] != '\0'){
		i++;
	}
	return i;
}
int restart(){
	system("cls");
	return main();
}
int shutdown(){
	printf("\n\n");
	system("PAUSE");
	return 0;
}