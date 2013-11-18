#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define POCET 100

typedef enum{ TRUE = 1, FALSE = 0 } Bool;

typedef struct{
	char* jmeno; char* prijmeni; char* adresa; char den; char mesic; int rok; char* telefon; char* email;
} osoba;

osoba vytvor_osobu(char jmeno[], char prijmeni[], char adresa[], char den, char mesic, int rok, char telefon[], char email[])
{
	osoba o;
	o.jmeno = jmeno;
	o.prijmeni = prijmeni;
	o.adresa = adresa;
	o.den = den;
	o.mesic = mesic;
	o.rok = rok;
	o.telefon = telefon;
	o.email = email;
	return o;
}

vytvor_seznam(osoba s[])
{
	int i;
	for (i = 0; i < POCET; i++){
		s[i].jmeno = 0;
		s[i].prijmeni = 0;
		s[i].adresa = 0;
		s[i].den = 0;
		s[i].mesic = 0;
		s[i].rok = 0;
		s[i].telefon = 0;
		s[i].email = 0;
	}
}

vloz(osoba s[], osoba o)
{
	int i;
	for (i = 0; i < POCET; i++){
		if (s[i].jmeno == 0){
			s[i] = o;
			return;
		}
	}
	printf("\nV seznamu osob jiz neni misto pro dalsi osobu.\n");
}

Bool najdi_osobu(char kde[], char co[], osoba s[])
{
	int i;
	for (i = 0; i < POCET; i++){
		if (kde == "jmeno" && s[i].jmeno == co)return TRUE;
		if (kde == "prijmeni" && s[i].prijmeni == co)return TRUE;
		if (kde == "adresa" && s[i].adresa == co)return TRUE;
		if (kde == "telefon" && s[i].telefon == co)return TRUE;
		if (kde == "email" && s[i].email == co)return TRUE;
	}
	return FALSE;
}

void tisk(osoba s[])
{
	int i;
	printf("Vypis seznamu osob:\n");
	for (i = 0; i < POCET; i++){
		if (s[i].jmeno == 0){
			break;
		}
		printf("%s %s\n", s[i].jmeno, s[i].prijmeni);
	}
	printf("\n");
}

osoba nejmladsi(osoba s[])
{
	int i;
	osoba o = s[0];
	for (i = 1; i < POCET; i++){
		if (s[i].rok > o.rok){
			o = s[i];
		}
		else if (s[i].rok == o.rok){
			if (s[i].mesic > o.mesic){
				o = s[i];
			}
			else if (s[i].mesic == o.mesic){
				if (s[i].den > o.den){
					o = s[i];
				}
			}
		}
	}
	return o;
}

int main()
{
	osoba seznam_osob[100], o1, o2, o3, o;
	vytvor_seznam(seznam_osob);
	o1 = vytvor_osobu("Alice", "Pokorna", "Holicka 62", 2, 1, 1992, "214 145 478", "alice.pokorna@email.cz");
	o2 = vytvor_osobu("Pavel", "Novak", "tr. 17 listopadu 24", 13, 1, 1992, "654 784 478", "pavel.novak@seznam.cz");
	o3 = vytvor_osobu("Ales", "Maly", "Holicka 62", 6, 5, 1989, "772 847 457", "ales.maly@upol.cz");
	vloz(seznam_osob, o1);
	vloz(seznam_osob, o2);
	vloz(seznam_osob, o3);
	tisk(seznam_osob);

	if (najdi_osobu("jmeno", "Alice", seznam_osob)) printf("Alice nalezena.\n"); else printf("Alice nenalezena.\n");
	if (najdi_osobu("prijmeni", "Novotny", seznam_osob)) printf("Novotny nalezen.\n"); else printf("Novotny nenalezen.\n");

	o = nejmladsi(seznam_osob);
	printf("Nejmladsi osobou v seznamu je %s %s.\n", o.jmeno, o.prijmeni);

	system("PAUSE");
	return 0;
}