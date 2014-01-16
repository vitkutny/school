#include <stdio.h>
float progresivniDan(int mzda){
	float vat=0,piece;
	int percent=10,i;
	for(i=0;i<mzda;i+=	10000){
		if(mzda - i >= 10000){
			piece=10000;
		}else{
			piece=mzda-i;
		}
		vat+=piece/100*percent;
		if(percent<30){
			percent+=10;
		}
	}
	return vat;
}
void main(){
	int mzda;
	printf("Zadejte Vasi mzdu: ");
	scanf("%d",&mzda);
	printf("\nOdpovidajici progresivni dan je: %.2f\n\n",progresivniDan(mzda));
	fflush(stdin);
	main();
}