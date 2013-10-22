#include <stdio.h>
void dve_nejvetsi_cisla(int a[],int n, int *first, int *second){
	int i;
	*first = a[0];
	*second = a[1];
	if(*second > *first){
		i = *second;
		*second = *first;
		*first = i;
	}
	for(i=0;i<=n-1;i++){
		if(a[i]>*second && a[i] < *first){
			*second = a[i];
		}else if(a[i]>*first){
			*first = a[i];
		}
	}
}
void main(){
	int i;
	int a[] ={-10,-11,20,19,17,150,-120,151,150,151};
	int n = 10;
	int first=0,second=0;

	dve_nejvetsi_cisla(a,n,&first,&second);
	printf("first: %d;second: %d;\n",first,second);

	system("PAUSE");
}