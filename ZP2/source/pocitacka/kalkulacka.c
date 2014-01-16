#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vypocty.h"

int main(int argc, char* argv[]){
	int i;
	int vypocet,cislo;
	if(argc < 2){
		printf("Napoveda:\n");
		printf("-c <velikost> - vypocet obsahu a obvodu ctverce\n");
		printf("-t <a> <b> <c> - vypocet obsahu a obvodu trojuhelniku\n");
		printf("<cislo> <+|-|*> <cislo> <+|-|*> <cislo>\n");
		return 0;
	}
	if(strlen(argv[1])==2 && argv[1][0]=='-'){
		switch (argv[1][1]){
		case 'c':
			if(argc >= 3){
				ctverec((long double)atof(argv[2]));
				return 0;
			}
			break;
		case 't':
			if(argc >= 5){
				trojuhelnik((long double)atof(argv[2]),(long double)atof(argv[3]),(long double)atof(argv[4]));
				return 0;
			}
			break;
		}
	}
	vypocet = atoi(argv[1]);
	for(i=2;i<argc;i++){
		if(argv[i][0]=='+' && i+1 < argc){
			vypocet += atoi(argv[i+1]);
		}else if(argv[i][0]=='-'){
			vypocet -= atoi(argv[i+1]);
		}else if(argv[i][0]=='*'){
			vypocet *= atoi(argv[i+1]);
		}
	}
	printf("Vypocet: %d\n",vypocet);
	return 0;
}