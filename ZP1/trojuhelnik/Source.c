#include <stdio.h>
void trojuhelnik(int n){
	int i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(n-j>=i){ //j<i
				printf(" ");
			}else{
				printf("*");
			}
		}
		printf("\n");
	}
}
void main(){
	int strana;
	printf("Zadejte velikost strany: ");
	scanf("%d",&strana);
	trojuhelnik(strana);
	printf("\n\n");
	fflush(stdin);
	main();
}