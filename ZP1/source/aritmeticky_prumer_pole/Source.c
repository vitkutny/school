#include <stdio.h>
double prumer(int pole[], int delka){
	int i;
	double prumer;
	int soucet=0;
	for(i=0;i<delka;i++){
		soucet+= (int) pole[i];
	}
	prumer = (double) soucet/delka;
	return prumer;
}
int main() {
	int pole[] = {1, 2, 3, 4};

	printf("%g\n", prumer(pole, 4)); // 2.5

	system("PAUSE");
}