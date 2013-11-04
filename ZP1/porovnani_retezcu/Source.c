#include <stdio.h>
#include <string.h>
int porovnej_retezce(char ret1[], char ret2[]){
	int i;
	for (i = 0; i <= strlen(ret1); i++){
		if (ret1[i] > ret2[i]){
			return 1;
		}
		else if (ret1[i] < ret2[i]){
			return -1;
		}
	}
	return 0;
}
void main() {
	porovnej_retezce("hromada", "hroznys"); // Funkce vrati zaporne cislo, "hromada" je v abecednim poradi pred "hroznys"
	porovnej_retezce("trollech", "trollech"); // Funkce vrati nulu, retezce jsou stejne
	porovnej_retezce("stiny plamenu", "stiny"); // Funkce vrati kladne cislo
	porovnej_retezce("Ab", "ab"); // Vrati zapornou hodnotu, "A" je v ASCII tabulce pred "a"
	porovnej_retezce("Coze?!", "Coze??"); // Vrati zapornou hodnotu

	system("PAUSE");
}