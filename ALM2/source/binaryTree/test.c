#include <stdio.h>
#include "binaryTree.h"
#include "testData.h"

int main(){
	int i;
	binaryTree* tree;
	tree = createTree(NULL);

	for (i = 0; i < Pocet; i++){
		treeInsert(tree, Jmena[i]);
	}
	printf("Vyska stromu je %d.\n\n", treeHeight(tree));
	system("PAUSE");
	treePrint(tree);
	system("PAUSE");
	return 0;
}

