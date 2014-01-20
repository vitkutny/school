#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s{
	char* value; int length; struct s *before;
} slovo;

int restart();
int shutdown();
void clear_screen();
int game(slovo, char*);
int already_used(slovo);
int in_dict(char*, char*);
void header();
void language_select(char**);
void get_first_word(slovo*);
char* dict_add(char*, char*);

int main(){
	slovo s;
	char* dict;

	clear_screen();
	language_select(&dict);
	get_first_word(&s);
	clear_screen();

	return game(s, dict);
}
int game(slovo s, char* dict){
	slovo s_new;
	s_new.value = (char*)malloc(sizeof(char)*(100));
	s_new.before = &s;
	printf("Predchozi slovo bylo: '%s'.\nZadejte slovo zacinajici na pismeno '%c': ", s.value, s.value[s.length - 1]);
	scanf("%s", s_new.value);
	s_new.length = strlen(s_new.value);

	if (strcmp(s_new.value, "shutdown") == 0){
		return shutdown();
	}
	if (strcmp(s_new.value, "restart") == 0){
		return restart();
	}

	clear_screen();

	if (s_new.value[0] != s.value[s.length - 1]){
		printf("Slovo '%s' nezacina na pismeno '%c'.\n\n", s_new.value, s.value[s.length - 1]);
		return game(s, dict);
	}
	if (s_new.value[strlen(s_new.value) - 1] == '+'){
		s_new.value = dict_add(s_new.value, dict);
		s_new.length = strlen(s_new.value);
	}
	if (!in_dict(dict, s_new.value)){
		printf("Slovo '%s' neni ve slovniku.\n\n", s_new.value);
		return game(s, dict);
	}
	if (already_used(s_new)){
		printf("Slovo '%s' jiz bylo ve hre pouzito.\n\n", s_new.value);
		return game(s, dict);
	}

	return game(s_new, dict);
}
int already_used(slovo s_new){
	int i;
	slovo s_temp = *s_new.before;
	while (s_temp.before != NULL){
		if (strcmp(s_temp.value, s_new.value) == 0){
			return 1;
		}
		s_temp = *s_temp.before;
	}
	return 0;
}
int in_dict(char* dict, char* word){
	FILE *file;
	char radek[512];
	int match = 0;
	int i;
	char* str;

	str = (char*)malloc(sizeof(char)*(strlen(word) + 2));
	for (i = 0; i < strlen(word); i++){
		str[i] = word[i];
	}
	str[i] = '\n';
	str[i + 1] = '\0';

	file = fopen(dict, "r");

	if (!file) {
		printf("Chyba pri otevirani slovniku '%s'.\n", dict);
		return 0;
	}

	while (fgets(radek, 512, file)){
		if (strcmp(radek, str) == 0){
			match = 1;
		}
	}

	if (file) {
		fclose(file);
	}
	return match;
}
void clear_screen(){
	system("CLS");
	header();
}
int restart(){
	clear_screen();
	return main();
}
int shutdown(){
	clear_screen();
	system("PAUSE");
	return 0;
}
void header(){
	printf("=================================");
	printf("Slovni fotbal!");
	printf("=================================");
	printf("\n");
}
void language_select(char** dict){
	int a;
	*dict = (char*)malloc(sizeof(char)* 100);
	printf("Vyberte jazyk:\n");
	printf("1 - Cestina\n2 - English\n0 - ze souboru\n");
	printf("Vase volba: ");
	scanf("%i", &a);

	switch (a){
	case 0:
		printf("\nZadejte nazev souboru: ");
		scanf("%s", *dict);
		break;
	case 2:
		*dict = "en.txt";
		break;
	case 1:
	default:
		*dict = "cz.txt";
		break;
	}
}
void get_first_word(slovo* s){
	(*s).length = 6;
	(*s).value = (char*)malloc(sizeof(char)*((*s).length + 1));
	(*s).value = "fotbal";
	(*s).before = NULL;
}
char* dict_add(char* word, char* dict){
	FILE* file;
	char* str;
	int i;
	str = (char*)malloc(sizeof(char)*(strlen(word) + 1));
	for (i = 0; i < strlen(word) - 1; i++){
		str[i] = word[i];
	}
	str[i] = '\n';
	str[i + 1] = '\0';

	file = fopen(dict, "a");
	if (!file) {
		printf("Chyba pri otevirani slovniku '%s'.\n", dict);
		return word;
	}

	fputs(str, file);

	if (file) {
		fclose(file);
	}

	str[i] = '\0';
	return str;
}