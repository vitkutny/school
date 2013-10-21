#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

long double prumer(char* format, ...){
	va_list parametry;
	int i,delka = strlen(format);
	long double soucet=0;
	long double prumer;
	int cislo_i;double cislo_d;long double cislo_l;
	va_start(parametry,format);
	for(i=0;i<delka;i++){
		switch(format[i]){
		case 'i':
			soucet+=(long double)va_arg(parametry,int);
			break;
		case 'd':
			soucet+=(long double)va_arg(parametry,double);
			break;
		case 'l':
			soucet+=(long double)va_arg(parametry,long double);
			break;
		}
	}
	va_end(parametry);
	prumer = (long double) soucet / i;
	return prumer;
}

int main(){

	assert(2.25 == prumer("idld", 1, (double)3, (long double)2, 3.0));
	assert(10 == prumer("iii", 5, 10, 15));
	assert(5.5 == prumer("d", (double)5.5));

	return 0;
}