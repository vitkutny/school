#ifndef _INC_BINARY_TREE
#define _INC_BINARY_TREE

typedef struct tree{
	char* value; struct tree* left; struct tree* right;
} binaryTree;

binaryTree* createTree(char*);
int treeInsert(binaryTree*, char*);
int treeHeight(binaryTree*);
void treePrint(binaryTree*);

#endif