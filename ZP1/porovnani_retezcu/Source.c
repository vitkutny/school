#include <stdio.h>
#include <string.h>
int porovnej_retezce(char* a, char* b){
	while (1){
		if (*a > *b){
			return 1;
		}
		else if (*a < *b){
			return -1;
		}
		else if (*a == '\0' || *b == '\0'){
			return 0;
		}
		a++;
		b++;
	}
}
void main() {
	porovnej_retezce("hromada", "hroznys"); // Funkce vrati zaporne cislo, "hromada" je v abecednim poradi pred "hroznys"
	porovnej_retezce("trollech", "trollech"); // Funkce vrati nulu, retezce jsou stejne
	porovnej_retezce("stiny plamenu", "stiny"); // Funkce vrati kladne cislo
	porovnej_retezce("Ab", "ab"); // Vrati zapornou hodnotu, "A" je v ASCII tabulce pred "a"
	porovnej_retezce("Coze?!", "Coze??"); // Vrati zapornou hodnotu

	system("PAUSE");
}