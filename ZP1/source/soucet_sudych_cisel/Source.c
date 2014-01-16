#include <stdio.h>
int soucet_sudych(int n){
	int i;
	int soucet=0;
	for(i=n;i>0;i--){
		soucet+=i*2;
	}
	return soucet;
}
int main() {
	printf("%i\n", soucet_sudych(1)); // 2
	printf("%i\n", soucet_sudych(2)); // 6
	printf("%i\n", soucet_sudych(3)); // 12
	printf("%i\n", soucet_sudych(9)); // 90
	
	system("PAUSE");
}