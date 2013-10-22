#include <stdio.h>
void dve_nejvetsi(int a[],int n, int *first, int *second){
	int i;
	*first = a[0];
	*second = a[1];
	if(*second > *first){
		i = *second;
		*second = *first;
		*first = i;
	}
	for(i=0;i<n-1;i++){
		if(a[i]>*second && a[i] < *first){
			*second = a[i];
		}else if(a[i]>*first){
			*first = a[i];
		}
	}
}
void main(){
	int i;
	int a[] ={10,30,15,29,13,9,5,28,19};
	int n = 9;
	int first=0,second=0;

	dve_nejvetsi(a,n,&first,&second);
	printf("first: %d;second: %d;\n",first,second);

	system("PAUSE");
}