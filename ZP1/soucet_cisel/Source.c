#include <stdio.h>
void secti(int a,int b, int *x){
	*x=a+b;
}
void main(){
	int a,b,x;
	printf("Zadejte dve cisla: ");
	scanf("%d %d",&a,&b);

	secti(a,b,&x);
	printf("Soucet cisel %d a %d je: %d\n\n",a,b,x);
	fflush(stdin);
	main();
}