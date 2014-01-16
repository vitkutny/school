#include <stdio.h>
#include <stdlib.h>
double **soucet_matic(int radky, int sloupce, double **A, double **B){
	int i,j;
	double** soucet = (double **) malloc(sizeof(double*)*radky);
	for(i=0;i<radky;i++){
		soucet[i] = (double *) malloc(sizeof(double)*sloupce);
	}

	for(i=0;i<radky;i++){
		for(j=0;j<sloupce;j++){
			soucet[i][j]=A[i][j]+B[i][j];
		}
	}

	return soucet;
}
void vypis_pole(double* pole,int delka){
	int i;
	for(i=0;i<delka;i++){
		printf("%.2f ",pole[i]);
	}
}
void main(){
	double** matice_a;
	double** matice_b;
	double** soucet;
	int radky = 2;
	int sloupce = 3;

	matice_a = (double **) malloc(sizeof(double*)*radky);
	matice_a[0] = (double *) malloc(sizeof(double)*sloupce);
	matice_a[1] = (double *) malloc(sizeof(double)*sloupce);
	matice_a[0][0]=1;
	matice_a[0][1]=2;
	matice_a[0][2]=3;
	matice_a[1][0]=4;
	matice_a[1][1]=5;
	matice_a[1][2]=6;
	matice_b = (double **) malloc(sizeof(double*)*radky);
	matice_b[0] = (double *) malloc(sizeof(double)*sloupce);
	matice_b[1] = (double *) malloc(sizeof(double)*sloupce);
	matice_b[0][0]=5;
	matice_b[0][1]=2;
	matice_b[0][2]=1;
	matice_b[1][0]=3;
	matice_b[1][1]=6;
	matice_b[1][2]=9;

	soucet = soucet_matic(radky,sloupce,matice_a,matice_b);

	vypis_pole(soucet[0],sloupce);
	printf("\n");
	vypis_pole(soucet[1],sloupce);

	printf("\n\n");
	system("PAUSE");
}