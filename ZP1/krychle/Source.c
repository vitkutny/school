#include <stdio.h>
void main(){
	int a;
	printf("Zadejte delku strany: ");
	scanf("%d",&a);
	printf("Povrch krychle: %d\n",6*a*a);
	printf("Objem krychle: %d",a*a*a);

	printf("\n\n");
	fflush(stdin);
	main();
}