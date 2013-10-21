#include <stdio.h>
void main(){
	int a,i,j;
	printf("Zadejte velikost ctverce: ");
	scanf("%d",&a);

	for(i=1;i<=a;i++){
		if((i==1)||(i==a)){
			for(j=1;j<=a;j++){
				printf("*");
			}
		}else{
			printf("*");
			for(j=1;j<=a-2;j++){
				printf(" ");
			}
			printf("*");
		}
		printf("\n");
	}

	fflush(stdin);
	main();
}