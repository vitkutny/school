#include <stdio.h>
int soucet_delitelu(int cislo){
	int i;
	int soucet = 0;
	for (i = 1; i <= cislo; i++){
		if (cislo%i == 0){
			soucet += i;
		}
	}
	return soucet;
}
int abundantni_cislo(int cislo){
	if (cislo * 2 < soucet_delitelu(cislo)){
		return 1;
	}
	return 0;
}
int abundantni_cisla(int n){
	int i;
	int soucet = 0;
	for (i = 1; i <= n; i++){
		if (abundantni_cislo(i)){
			soucet++;
		}
	}
	return soucet;
}
int main(){
	printf("%i\n", abundantni_cisla(25)); //4, protože existují 4 abundantní čísla menší než 25 (jsou to: 12, 18, 20, 24)
	printf("%i\n", abundantni_cisla(10000000)); //by mělo trvat řádově sekundy, ne desítky sekund či několik minut.
	system("PAUSE");
	return 0;
}