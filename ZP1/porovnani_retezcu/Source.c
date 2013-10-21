#include <stdio.h>
int porovnani_retezcu(char ret1[], char ret2[]){
	if(ret1 == ret2){
		return 1;
	}else{
		return 0;
	}
}
void main() {
	printf("%i\n", porovnani_retezcu("jazyk", "jazyk")); // 1
	printf("%i\n", porovnani_retezcu("jazyk", "jazyky")); // 0
	printf("%i\n", porovnani_retezcu("?!", "?!")); // 1
	printf("%i\n", porovnani_retezcu("?!", "QR")); // 0

	system("PAUSE");
}