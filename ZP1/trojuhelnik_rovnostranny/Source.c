#include <stdio.h>
void trojuhelnik_rovnostranny(int n){
	int i,j;
	for(i=0;i<=n;i++){
		for(j=0;j<=2*n;j++){
			if(j==n-i || j==n+i || i==n){
				printf("X");
			}else{
				printf(" ");
			}
		}
		printf("\n");
	}
}
void restart(){
	printf("\n\n");
	fflush(stdin);
	main();
}
int main(){
	int n,i;
	printf("Zadej cislo n: ");
	scanf("%d",&n);
	if(n<1 || n>11){
		printf("Cislo n musi byt v rozmezi (1-11).");
		restart();
	}

	for(i=1;i<=n;i++){
		printf("\n\n");
		trojuhelnik_rovnostranny(i);
	}

	restart();
}