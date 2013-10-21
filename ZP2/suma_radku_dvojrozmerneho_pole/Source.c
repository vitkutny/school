#include <stdio.h>
#include <stdlib.h>
int *suma_radku(int prvky[][4], int radku){
	int* soucty=(int *)malloc(sizeof(int)*radku);
	int i,j;
	for(i=0;i<=radku;i++){
		int soucet = 0;
		for(j=0;j<4;j++){
			soucet += prvky[i][j];
		}
		soucty[i]=soucet;
	}
	return soucty;
}
void vypis_pole(int* pole,int delka){
	int i;
	for(i=0;i<delka;i++){
		printf("%d ",pole[i]);
	}
}
void main(){
	int prvky[][4] = {{10,2,15,-2},{-52,41,0,12},{15,3,1,-8}};
	int radku = 3;

	printf("Soucty na radcich jsou: ");
	vypis_pole(suma_radku(prvky,radku),radku);

	printf("\n\n");
	system("PAUSE");
}