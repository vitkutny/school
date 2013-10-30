#include <stdio.h>

int shutdown();
int restart();
void vykresleni_kosoctverce(int);

int main(){
	int n;
	printf("Zadejte cislo n: ");
	scanf("%d", &n);

	if (n<1 || n >30){
		printf("\nCislo n nesmi byt vetsi nez 30.");
		return restart();
	}

	vykresleni_kosoctverce(n);

	return shutdown();
}

void vykresleni_kosoctverce(int n){
	int i, j, strana;
	strana = 2 * n + 1;
	for (i = 0; i < strana; i++){
		for (j = 0; j < strana; j++){
			if (j == strana / 2 - i || j == strana / 2 + i || i == strana / 2 + j || i == 3 * n - j){
				printf("X");
			}
			else{
				printf(" ");
			}
		}
		printf("\n");
	}
}

int shutdown(){
	printf("\n\n");
	system("PAUSE");
	return 0;
}

int restart(){
	printf("\n\n");
	return main();
}