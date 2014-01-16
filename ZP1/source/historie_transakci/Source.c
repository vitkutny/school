#include <stdio.h>
typedef struct{
	int den,mesic,rok;
} datum;
typedef struct{
	double castka;int varsymbol;datum splatnost;
} transakce;
int porovnej_datum(datum d1, datum d2){
	if(d1.rok > d2.rok){
		return 1;
	}else if(d2.rok>d1.rok){
		return -1;
	}else{
		if(d1.mesic > d2.mesic){
			return 1;
		}else if (d2.mesic > d1.mesic){
			return -1;
		}else{
			if(d1.den>d2.den){
				return 1;
			}else if(d2.den>d1.den){
				return -1;
			}else{
				return 0;
			}
		}
	}
}
int porovnej_splatnost(transakce t1,transakce t2){
	return porovnej_datum(t1.splatnost,t2.splatnost);
}
void main(){
	transakce najem = {11000,2012125,{1,12,2012}};
	transakce mzda = {29537.32,201212587,{16,12,2012}};
	printf("Najem, mzda: %d\n",porovnej_splatnost(najem, mzda));
	printf("Mzda, najem: %d\n",porovnej_splatnost(mzda, najem));
	printf("Mzda, mzda: %d",porovnej_splatnost(mzda, mzda));

	printf("\n\n");
	system("PAUSE");
}