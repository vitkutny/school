#include <stdio.h>
#include <stdlib.h>

int analyza_textu(char*, int);

int main(){
	char t[] = "Ahoj      svete!!!!! Ono to prekvapive aj funguje,     jupi  !";
	int max = 0;
	int pocet;
	pocet = analyza_textu(t, &max);
	printf("Retezec \"%s\" ma %d slov. Nejdelsi slovo ma %d znaku.\n", t, pocet, max); //13
	system("PAUSE");
	return 0;
}

int analyza_textu(char* text, int* max){
	int i = 0;
	int pocet_znaku = 0;
	int pocet_slov = 0;

	while (text[i] != '\0'){
		switch (text[i]){
		case '.':
		case ',':
		case ';':
		case '?':
		case '!':
		case ' ':
			if (pocet_znaku > *max){
				*max = pocet_znaku;
			}
			if (pocet_znaku){
				pocet_slov++;
			}
			pocet_znaku = 0;
			break;
		default:
			pocet_znaku++;
			break;
		}
		i++;
	}
	return pocet_slov;
}