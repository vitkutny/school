#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	int id; char* title; char*(*function)(char*);
} function;

char *smallLetters(char *t);
char *bigLetters(char *t);
char *reverseString(char *t);

int main()
{
	char string[255], *vystup;
	int cislo, i;
	function seznam[3];
	seznam[0].id = 1;
	seznam[0].title = "Funkce vrati pouze velka pismena";
	seznam[0].function = bigLetters;
	seznam[1].id = 2;
	seznam[1].title = "Funkce vrati pouze mala pismena";
	seznam[1].function = smallLetters;
	seznam[2].id = 3;
	seznam[2].title = "Funkce vrati zadany text pozpatku";
	seznam[2].function = reverseString;

	for (i = 0; i<3; i++){
		printf("%d - %s\n", seznam[i].id, seznam[i].title);
	}
	printf("\nVyber funkci(1-3), kterou chces pouzit: ");
	scanf("%d", &cislo);
	if ((cislo>0) && (cislo < 4))
	{
		printf("\nZadej vstupni retezec: ");
		fflush(stdin);
		gets(string);
		vystup = seznam[cislo - 1].function(string);
		printf("\n%s\n", vystup);
	}

	system("PAUSE");
	return 0;
}

char *smallLetters(char *string){
	int i;
	int size = 0;
	char* smallLetters;
	smallLetters = (char*)malloc(NULL);

	for (i = 0; i <= strlen(string); i++){
		if ((string[i] >= 'a' && string[i] <= 'z') || string[i] == '\0'){
			size++;
			smallLetters = (char*)realloc(smallLetters, sizeof(char)*(size));
			smallLetters[size - 1] = string[i];
		}
	}

	return smallLetters;
}

char *bigLetters(char *string){
	int i;
	int size = 0;
	char* bigLetters;
	bigLetters = (char*)malloc(NULL);

	for (i = 0; i <= strlen(string); i++){
		if ((string[i] >= 'A' && string[i] <= 'Z') || string[i] == '\0'){
			size++;
			bigLetters = (char*)realloc(bigLetters, sizeof(char)*(size));
			bigLetters[size - 1] = string[i];
		}
	}

	return bigLetters;
}

char *reverseString(char *string){
	int i;
	char* reversed;
	reversed = (char*)malloc(sizeof(char)*(strlen(string) + 1));
	for (i = 0; i < strlen(string); i++){
		reversed[i] = string[strlen(string) - i - 1];
	}
	reversed[i] = '\0';
	return reversed;
}