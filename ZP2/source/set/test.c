#include <stdio.h>
#include "set.h"

int main(){
	set* A = setCreate();
	set* B = setCreate();

	setInsert(A, 5);
	setInsert(A, 12);
	setInsert(A, 8);
	setInsert(A, 7);
	setInsert(A, 14);
	setInsert(A, 20);
	printf("Set A: ");
	setPrint(A);
	setRemove(A, 20);
	printf("Remove 20 from A: ");
	setPrint(A);
	printf("Try to remove 4 from A: ");
	if (!setRemove(A, 4)){
		printf("4 is not in set A.\n");
	}

	setInsert(B, 5);
	setInsert(B, 14);
	setInsert(B, 9);
	setInsert(B, 7);
	setInsert(B, 19);
	printf("Set B: ");
	setPrint(B);

	printf("A union B: ");
	setPrint(setUnion(A, B));

	printf("A intersection B: ");
	setPrint(setIntersection(A, B));

	printf("A difference B: ");
	setPrint(setDifference(A, B));

	printf("A intersection B union B difference A: ");
	setPrint(setProccess("iud", A, B, B, A));

	system("PAUSE");
	return 0;
}