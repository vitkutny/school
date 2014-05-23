#include <assert.h>
#include <stdio.h>
#include <stdarg.h>
int suma(int zacatek, ...){
	va_list parametry;
	int soucet=0,cislo;
	if(!zacatek){
		return soucet;
	}
	soucet += zacatek;

	va_start(parametry,zacatek);
	while(cislo = va_arg(parametry,int)){
		soucet += cislo;
	}
	va_end(parametry);

	return soucet;
}
int main(){
	assert(10 == suma(5, 2, 3, 0));
	assert(5 == suma(5, 2, 3, -5, 0));
	assert(42 == suma(42, 0));
	assert(0 == suma(0));
	assert(0 == suma(0, 7));

	return 0;
}