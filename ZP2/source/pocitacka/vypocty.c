#include <stdio.h>
#include <math.h>
void ctverec(long double a){
	long double obvod = a * 4;
	long double obsah = a * a;
	printf("Obvod ctverce je: %g\n",obvod);
	printf("Obsah ctverce je: %g\n",obsah);
}
void trojuhelnik(long double a,long double b, long double c){
	long double obvod,obsah,s,heronuv_vzorec;
	obvod = a + b + c;
	s=obvod/2;
	obsah = sqrt(s*(s-a)*(s-b)*(s-c));
	printf("Obvod trojuhelniku je: %g\n",obvod);
	printf("Obsah trojuhelniku je: %g\n",obsah);
}