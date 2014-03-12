#include <stdio.h>
#include <stdlib.h>

int** relationCreate(int);
void relationPrint(int**, int);
int** reflexiveClosure(int**, int);
int** symmetricClosure(int**, int);
int** transitiveClosure(int**, int);
int shutdown();

int main(){
	int size = 5;
	int** relation = relationCreate(size);
	relation[0][2] = 1;
	relation[1][2] = 1;
	relation[2][0] = 1;
	relation[2][2] = 1;
	relation[2][4] = 1;


	relationPrint(relation, size);
	printf("Reflexive closure of ");
	relationPrint(reflexiveClosure(relation, size), size);
	printf("Symmetric closure of ");
	relationPrint(symmetricClosure(relation, size), size);
	printf("Transitive closure of ");
	relationPrint(transitiveClosure(relation, size), size);

	return shutdown();
}

int** relationCreate(int size){
	int x, y;
	int** relation;
	relation = (int**)malloc(sizeof(int*)*size);
	for (x = 0; x < size; x++){
		relation[x] = (int*)malloc(sizeof(int)*size);
		for (y = 0; y < size; y++){
			relation[x][y] = NULL;
		}
	}
	return relation;
}

void relationPrint(int** relation, int size){
	int x, y, count = 1;
	printf("R = {");
	for (x = 0; x < size; x++){
		count = 0;
		for (y = 0; y < size; y++){
			if (relation[x][y]){
				if (!count){
					printf("\n\t");
				}
				else{
					printf(", ");
				}
				count++;
				printf("<%d;%d>", x, y);
			}
		}
	}
	printf("}\n\n");
}

int** reflexiveClosure(int** relation, int size){
	int** closure = relationCreate(size);
	int x, y;

	for (x = 0; x < size; x++){
		for (y = 0; y < size; y++){
			closure[x][y] = (x == y) ? 1 : relation[x][y];
		}
	}

	return closure;
}

int** symmetricClosure(int** relation, int size){
	int** closure = relationCreate(size);
	int x, y;

	for (x = 0; x < size; x++){
		for (y = 0; y < size; y++){
			if (relation[x][y]){
				closure[x][y] = closure[y][x] = relation[x][y];
			}
		}
	}

	return closure;
}

int** transitiveClosure(int** relation, int size){
	int** closure = relationCreate(size);
	int x, y, z;

	for (x = 0; x < size; x++){
		for (y = 0; y < size; y++){
			if (!closure[x][y]){
				closure[x][y] = relation[x][y];
			}
			if (relation[x][y]){
				for (z = 0; z < size; z++){
					if (relation[y][z]){
						closure[x][z] = 1;
					}
				}
			}
		}
	}

	return closure;
}

int shutdown(){
	printf("\n\n");
	system("PAUSE");
	return 0;
}