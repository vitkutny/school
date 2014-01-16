#include <stdio.h>
char* strTypeOf(char znak){
	if(znak >= 'a' && znak <='z'){
		return "male pismeno";
	}else if(znak >= 'A' && znak <= 'Z'){
		return "velke pismeno";
	}else if(znak >= 0 && znak <= 9){
		return "cislice";
	}else switch(znak){
	case '!':
		return "vykricnik";
		break;
	case '?':
		return "otaznik";
		break;
	case '*':
		return "hvezdicka";
		break;
	case '@':
		return "zavinac";
		break;
	case '#':
		return "krizek";
		break;
	case '^':
		return "striska";
		break;
	default:
		return "jiny znak";
		break;
	}
}
void main(){
	char znak;
	printf("Zadejte znak: ");
	scanf("%c",&znak);
	printf("Zadany znak je %s %c\n\n",strTypeOf(znak),znak);
	fflush(stdin);
	main();
}