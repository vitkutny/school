#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#define TABLE_SIZE 5003

typedef struct s {
	int size; char** data;
} hashTable;

hashTable* hashTableCreate(int);
unsigned int baseHash(char*);
int primaryHash(char*);
int secondaryHash(char*);
int linearInsert(hashTable*, char*);
int quadraticInsert(hashTable*, char*);
int doubleInsert(hashTable*, char*);
int hashTableFind(hashTable*, char*);
char* generateString(int);
void tableHeader();
void tableRow(int, double, double, double);
int shutdown();

int main(){
	hashTable* linearTable = hashTableCreate(TABLE_SIZE);
	hashTable* quadraticTable = hashTableCreate(TABLE_SIZE);
	hashTable* doubleTable = hashTableCreate(TABLE_SIZE);
	int i, j, linearCount, quadraticCount, doubleCount;
	int linearSum = 0, quadraticSum = 0, doubleSum = 0;
	int percents[] = { 50, 75, 90, 95 };
	int percents_count = 4;
	char* string;

	tableHeader();
	srand((unsigned int)time(NULL));

	for (i = 0; i < TABLE_SIZE * percents[percents_count - 1] / 100; i++){
		do{
			string = generateString((rand() % 10) + 1);
			linearCount = linearInsert(linearTable, string);
			quadraticCount = quadraticInsert(quadraticTable, string);
			doubleCount = doubleInsert(doubleTable, string);
		} while (!linearCount || !quadraticCount || !doubleCount);

		linearSum += linearCount;
		quadraticSum += quadraticCount;
		doubleSum += doubleCount;

		for (j = 0; j < percents_count; j++){
			if (i == (TABLE_SIZE - 1) * percents[j] / 100){
				tableRow(percents[j], (double)linearSum / (i + 1), (double)quadraticSum / (i + 1), (double)doubleSum / (i + 1));
			}
		}
	}

	return shutdown();
}

hashTable* hashTableCreate(int size){
	int i;
	hashTable* table;
	table = (hashTable*)malloc(sizeof(hashTable));
	table->size = size;
	table->data = (char**)malloc(sizeof(char*)*size);
	for (i = 0; i < size; i++){
		table->data[i] = NULL;
	}
	return table;
}

unsigned int baseHash(char* string){
	unsigned int value = 0;
	int i, prime = 37, length = strlen(string);
	for (i = 0; i < length; i++){
		value += pow(prime, length - i) * (int)string[i];
	}
	return value;
}

int primaryHash(char* string){
	return baseHash(string) % TABLE_SIZE;
}

int secondaryHash(char* string){
	return (1 + (baseHash(string) % (TABLE_SIZE - 1)));
}

int linearInsert(hashTable* table, char* string){
	int hash, default_hash, count = 0;
	if (hashTableFind(table, string)){
		return 0;
	}
	hash = default_hash = primaryHash(string);
	do{
		count++;
		if (!table->data[hash]){
			table->data[hash] = string;
			return count;
		}
		hash = (hash + 1) % table->size;
	} while (hash != default_hash);
	return 0;
}

int quadraticInsert(hashTable* table, char* string){
	int i, hash, default_hash;
	if (hashTableFind(table, string)){
		return 0;
	}
	default_hash = primaryHash(string);
	for (i = 0; i < table->size; i++){
		hash = (default_hash + i*i) % table->size;
		if (!table->data[hash]){
			table->data[hash] = string;
			return i + 1;
		}
	}
	return 0;
}

int doubleInsert(hashTable* table, char* string){
	int i, hash, secondary_hash;
	if (hashTableFind(table, string)){
		return 0;
	}
	hash = primaryHash(string);
	secondary_hash = secondaryHash(string);
	for (i = 0; i < table->size; i++){
		if (!table->data[hash]){
			table->data[hash] = string;
			return i + 1;
		}
		hash = (hash + secondary_hash) % table->size;
	}
	return 0;
}

int hashTableFind(hashTable* table, char* string){
	int i;
	for (i = 0; i < table->size; i++){
		if (table->data[i] && strcmp(table->data[i], string) == 0){
			return 1;
		}
	}
	return 0;
}

char* generateString(int size){
	char* string = (char*)malloc(sizeof(char)*(size + 1));
	int i;
	for (i = 0; i < size; i++){
		string[i] = (char)'a' + rand() % ('z' - 'a' + 1);
	}
	string[i] = '\0';
	return string;
}

void tableHeader(){
	int i;
	printf("%5s", "|");
	printf("%6s%10s%7s\n", "Linear", "Quadratic", "Double");
	for (i = 0; i < 4; i++){
		printf("=");
	}
	printf("|");
	for (i = 0; i < 23; i++){
		printf("=");
	}
	printf("\n");
}

void tableRow(int percent, double r1, double r2, double r3){
	printf("%3d%%|", percent);
	printf("%6.2f%10.2f%7.2f\n", r1, r2, r3);
}

int shutdown(){
	printf("\n\n");
	system("PAUSE");
	return 0;
}