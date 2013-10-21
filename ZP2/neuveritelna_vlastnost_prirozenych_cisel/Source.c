#include <stdio.h>
int terminator_posloupnosti(int x){
	int i;
	int soucet=0;
	while(x > 0){
		soucet += (x % 10) * (x % 10);
		x /= 10;
	}
	if(soucet == 89 || soucet == 1){
		return soucet;
	}else{
		return terminator_posloupnosti(soucet);
	}
}

void main(){
	printf("%i\n", terminator_posloupnosti(1)); // 1
	printf("%i\n", terminator_posloupnosti(44)); // 1
	printf("%i\n", terminator_posloupnosti(32)); // 1
	printf("%i\n", terminator_posloupnosti(44222)); // 1

	printf("%i\n", terminator_posloupnosti(89)); // 89
	printf("%i\n", terminator_posloupnosti(37)); // 89
	printf("%i\n", terminator_posloupnosti(20)); // 89
	printf("%i\n", terminator_posloupnosti(666)); // 89
	system("PAUSE");
}