#include <stdio.h>
void main(){
	int n=4;
	int i,j,k;
	int krat;

	printf("Zadejte cislo n: ");
	scanf("%d",&n);

	if(n>12){
		printf("Cislo n nesmi byt vetsi 12.\n\n");
		main();
	}

	for(k=1;k<=n;k++){
		krat = 2*k+1;
		for(i=0;i<krat;i++){
			for(j=0;j<krat;j++){
				if(j==i || j==krat-i-1){
					printf("x");
				}else{
					printf(" ");
				}
			}
			printf("\n");
		}
		printf("\n");
	}

	printf("\n\n");
	system("PAUSE");
}