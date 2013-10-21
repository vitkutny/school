#include <stdio.h>
void main(){
	char retezec[100];
	int pole[255];
	int i;
	int ascii;

	gets(retezec);

	for(i=0;retezec[i]!='\0';i++){
		ascii = (int) retezec[i];
		if(pole[ascii]<=0){
			pole[ascii]=1;
		}else{
			pole[ascii]+=1;
		}
	}
	printf("Cetnost znaku pro \'%s\'\n\n",retezec);
	for(i=0;i<255;i++){
		if(pole[i]>=0){
			printf("%c - %d\n",i,pole[i]);
		}
	}

	printf("\n\n");
	system("PAUSE");
}