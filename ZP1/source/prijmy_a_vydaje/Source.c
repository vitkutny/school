#include <stdio.h>
double zustatek=0;
double prijem(double castka){
	static double prijmy = 0;
	zustatek += castka;
	prijmy += castka;
	return prijmy;
}
double vydaj(double castka){
	static double vydaje = 0;
	if(zustatek>=castka){
		zustatek -= castka;
		vydaje += castka;
	}
	return vydaje;
}
void main(){
	printf("Zustatek: %g\n", zustatek);        // Zustatek: 0
	printf("Prijmy: %g\n", prijem(1500));      // Prijmy: 1500
	printf("Prijmy: %g\n", prijem(4000));      // Prijmy: 5500 
	printf("Vydaje: %g\n", vydaj(500));        // Vydaje: 500
	printf("Zustatek: %g\n", zustatek);        // Zustatek: 5000
	printf("Prijmy: %g\n", prijem(1000));      // Prijmy: 6500
	printf("Vydaje: %g\n", vydaj(2500));       // Vydaje: 3000
	printf("Zustatek: %g\n", zustatek);        // Zustatek: 3500
	printf("Vydaje: %g\n", vydaj(150000));     // Vydaje: 3000
	printf("Zustatek: %g\n", zustatek);        // Zustatek: 3500
	printf("Prijmy: %g\n", prijem(500000));    // Prijmy: 506500
	printf("Vydaje: %g\n", vydaj(150000));     // Vydaje: 153000
	printf("Zustatek: %g\n", zustatek);        // Zustatek: 353500

	printf("\n\n");
	system("PAUSE");
}