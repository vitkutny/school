#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s{
	char* value; int length; struct s *before;
} slovo;

int restart();
int shutdown();
void clear_screen();
int game(slovo);
int already_used(slovo);
int in_dictionary(char*);
int strmatch(char*, char*);
void header();

int main(){
	slovo s;
	s.length = 6;
	s.value = (char*)malloc(sizeof(char)*(s.length + 1));
	s.value = "fotbal";
	s.before = NULL;

	header();
	system("PAUSE");
	clear_screen();
	return game(s);
}
int game(slovo s){
	slovo s_new;
	s_new.value = (char*)malloc(sizeof(char)*(100));
	s_new.before = &s;
	printf("Predchozi slovo bylo: '%s'.\nZadejte slovo zacinajici na pismeno '%c': ", s.value, s.value[s.length - 1]);
	scanf("%s", s_new.value);
	s_new.length = strlen(s_new.value);

	if (strmatch(s_new.value, "shutdown")){
		return shutdown();
	}
	if (strmatch(s_new.value, "restart")){
		return restart();
	}

	clear_screen();

	if (s_new.value[0] != s.value[s.length - 1]){
		printf("Slovo '%s' nezacina na pismeno '%c'.\n\n", s_new.value, s.value[s.length - 1]);
		return game(s);
	}
	if (!in_dictionary("cz.txt", s_new.value)){
		printf("Slovo '%s' neni ve slovniku.\n\n", s_new.value);
		return game(s);
	}
	if (already_used(s_new)){
		printf("Slovo '%s' jiz bylo ve hre pouzito.\n\n", s_new.value);
		return game(s);
	}

	return game(s_new);
}
int already_used(slovo s_new){
	int i;
	slovo s_temp = *s_new.before;
	while (s_temp.before != NULL){
		if (strmatch(s_temp.value, s_new.value)){
			return 1;
		}
		s_temp = *s_temp.before;
	}
	return 0;
}
int in_dictionary(char* dictionary, char* word){
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

	file = fopen(dictionary, "r");

	if (!file) {
		return 0;
	}

	while (fgets(radek, 512, file)){
		if (strmatch(radek, str)){
			match = 1;
		}
	}

	if (file) {
		fclose(file);
	}
	return match;
}
int strmatch(char* a, char* b){
	int i = 0;
	for (i = 0; i < strlen(a) || a[i] != b[i]; i++){
		if (a[i] != b[i]){
			return 0;
		}
	}
	if (i == strlen(b)){
		return 1;
	}
	return 0;
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