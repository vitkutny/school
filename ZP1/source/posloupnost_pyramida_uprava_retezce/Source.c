#include <stdio.h>
#include <stdlib.h>

int je_posloupnost_rostouci(int* posloupnost, int delka){
	int i;
	for (i = 1; i < delka; i++){
		if (posloupnost[i] <= posloupnost[i - 1]){
			return 0;
		}
	}
	return 1;
}
void nakresli_pyramidu(int vyska){
	int i, j, sirka;
	sirka = (2 * vyska - 1);
	for (i = 0; i < vyska; i++){
		for (j = 0; j < sirka; j++){
			if (j >= i && j < sirka - i){
				printf("*");
			}
			else{
				printf(" ");
			}
		}
		printf("\n");
	}
}
char* zmen_znak(const char* retezec, char puvodni, char novy){
	char* novy_retezec;
	int i, delka = 0;
	while (retezec[delka] != '\0')delka++;

	novy_retezec = (char*)malloc(sizeof(char)*(delka + 1));

	for (i = 0; i < delka; i++){
		if (retezec[i] == puvodni){
			novy_retezec[i] = novy;
		}
		else{
			novy_retezec[i] = retezec[i];
		}
	}

	novy_retezec[i] = '\0';

	return novy_retezec;
}
char* posun_retezec(const char* retezec){
	char* posunuty_retezec;
	int i, delka = 0;
	while (retezec[delka] != '\0')delka++;

	posunuty_retezec = (char*)malloc(sizeof(char)*(delka + 1));

	for (i = 0; i < delka - 1; i++){
		posunuty_retezec[i] = retezec[i + 1];
	}

	posunuty_retezec[i] = retezec[0];
	posunuty_retezec[i + 1] = '\0';

	return posunuty_retezec;
}
int main(){
	//je_posloupnost_rostouci
	printf("Rostouci posloupnost:\n\n");
	int posloupnost1[] = { 2, 4, 6, 8, 10 };
	int posloupnost2[] = { 2, 4, 6, 8, 12 };
	int posloupnost3[] = { 7, 4, 1, -2 };
	int posloupnost4[] = { 7, 0, 1, -2 };
	int posloupnost5[] = { 7, 15 };
	int posloupnost6[] = { 42 };
	int posloupnost7[] = { 1, 2, 3, 3 };

	printf("Je rostouci: %i\n", je_posloupnost_rostouci(posloupnost1, 5)); // Je rostouci: 1
	printf("Je rostouci: %i\n", je_posloupnost_rostouci(posloupnost2, 5)); // Je rostouci: 1
	printf("Je rostouci: %i\n", je_posloupnost_rostouci(posloupnost3, 4)); // Je rostouci: 0
	printf("Je rostouci: %i\n", je_posloupnost_rostouci(posloupnost4, 4)); // Je rostouci: 0
	printf("Je rostouci: %i\n", je_posloupnost_rostouci(posloupnost5, 2)); // Je rostouci: 1
	printf("Je rostouci: %i\n", je_posloupnost_rostouci(posloupnost6, 1)); // Je rostouci: 1
	printf("Je rostouci: %i\n", je_posloupnost_rostouci(posloupnost7, 4)); // Je rostouci: 0

	//nakresli_pyramidu
	printf("\n\nPyramida:\n\n");
	nakresli_pyramidu(5);

	//zmen_znak
	printf("\n\nZamena znaku:\n\n");
	printf("%s\n", zmen_znak("abcd", 'd', 'a')); // abca
	printf("%s\n", zmen_znak("abeceda", 'a', '!')); // !beced!
	printf("%s\n", zmen_znak("QQQQQQwwwww", 'Q', 'w')); // wwwwwwwwwww
	printf("%s\n", zmen_znak("123123", '1', '1')); // 123123
	printf("%s\n", zmen_znak("nejsem tady", '!', '1')); // nejsem tady

	//posun_retezec
	printf("\n\nPosun retezec:\n\n");
	printf("%s\n", posun_retezec("abcd")); // bcda
	printf("%s\n", posun_retezec("x")); // x
	printf("%s\n", posun_retezec("qwertz")); // wertzq
	printf("%s\n", posun_retezec("123456789")); // 234567891

	system("PAUSE");
	return 0;
}