#include <stdio.h>
char* strrstr(char* text, char* hledany){
	int i,j,found;
	int index=0;
	for(i=0;text[i]!='\0';i++){
		j=0;
		if(text[i]==hledany[j]){
			found = 1;
			for(j=0;hledany[j]!='\0';j++){
				if(hledany[j]!=text[i+j]){
					found = 0;
				}
			}
			if(found){
				index = i;
			}
		}
	}
	if(index){
		text+=index;
		return text;
	}
	return NULL;
}
void main(){
	printf("%s\n", strrstr("Tohle slovo slovo slovo je krasne.", "slovo")); // slovo je krasne.
	printf("%s\n", strrstr("Tohle slovo slovo slovo je krasne.", "slovo s")); // slovo slovo je krasne.
	printf("%s\n", strrstr("Tohle slovo slovo slovo je krasne.", "ohle")); // ohle slovo slovo slovo je krasne.
	strrstr("Tohle slovo slovo slovo je krasne.", "Nathan"); // vraci (null)
	printf("%s\n", strrstr("To neni jeptiska! Je to podplukovnik matka Tereza!", "podplukovnik")); // podplukovnik matka Tereza!
	printf("%s\n", strrstr("To neni jeptiska! Je to podplukovnik matka Tereza!", "ka")); // ka Tereza!
	printf("%s\n", strrstr("To neni jeptiska! Je to podplukovnik matka Tereza!", "ka!")); // ka! Je to podplukovnik matka Tereza!
	strrstr("To neni jeptiska! Je to podplukovnik matka Tereza!", "Rimmer"); // vraci (null)
	printf("\n\n");
	system("PAUSE");
}