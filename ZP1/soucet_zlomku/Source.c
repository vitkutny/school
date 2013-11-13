#include <stdio.h>
typedef struct {
	int citatel, jmenovatel;
} zlomek;

zlomek soucet_zlomku(zlomek, zlomek);
void vytiskni_zlomek(zlomek);
zlomek zkrat(zlomek);

void main(){
	zlomek z1 = { 2, 3 }, z2 = { -1, 6 };
	zlomek soucet = soucet_zlomku(z1, z2);
	vytiskni_zlomek(z1);
	printf(" + ");
	vytiskni_zlomek(z2);
	printf(" = ");
	vytiskni_zlomek(soucet);

	printf("\n\n");
	system("PAUSE");
}
zlomek soucet_zlomku(zlomek z1, zlomek z2){
	int i = 1;
	zlomek soucet;
	while (1){
		if ((i % z1.jmenovatel == 0) && (i % z2.jmenovatel == 0)){
			soucet.jmenovatel = i;
			break;
		}
		i++;
	}
	soucet.citatel = (soucet.jmenovatel / z1.jmenovatel*z1.citatel) + (soucet.jmenovatel / z2.jmenovatel*z2.citatel);
	return zkrat(soucet);
}
void vytiskni_zlomek(zlomek z){
	printf("%d/%d", z.citatel, z.jmenovatel);
}
zlomek zkrat(zlomek z){
	while (z.jmenovatel%z.citatel == 0 && z.citatel != 1){
		z.jmenovatel /= z.citatel;
		z.citatel /= z.citatel;
	}
	return z;
}