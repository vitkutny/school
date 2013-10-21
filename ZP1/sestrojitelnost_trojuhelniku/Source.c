#include <stdio.h>
void main(){
	int a,b,c;
	printf("Zadejte delky stran: ");
	scanf("%d %d %d",&a,&b,&c);
	printf("Trojuhelnik %d, %d a %d ",a,b,c);
	if((a<b+c)&&(b<a+c)&&(c<a+b)){
		printf("lze");
	}else{
		printf("nelze");
	}
	printf(" sestrojit\n\n");
	fflush(stdin);
	main();
}