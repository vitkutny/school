#include <stdio.h>

int shutdown();
int restart();
int abs(int);
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
	int i, j;
	for (i = -n; i <= n; i++){
		for (j = -n; j <= n; j++){
			if (abs(j) == n - i || abs(j) == n + i){
				printf("X");
			}
			else{
				printf(" ");
			}
		}
		printf("\n");
	}
}

int abs(int n){
	if (n < 0){
		return n*-1;
	}
	else{
		return n;
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