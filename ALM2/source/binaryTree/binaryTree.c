#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binaryTree.h"

binaryTree* createTree(char* value){
	binaryTree* node;
	node = (binaryTree*)malloc(sizeof(binaryTree));
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	return node;
}

int treeInsert(binaryTree* tree, char* value){
	if (tree->value == NULL){
		tree->value = value;
	}
	while (1){
		if (strcmp(value, tree->value) == -1){
			if (tree->left == NULL){
				tree->left = createTree(value);
				return 1;
			}
			tree = tree->left;
		}
		else if (strcmp(value, tree->value) == 1){
			if (tree->right == NULL){
				tree->right = createTree(value);
				return 1;
			}
			tree = tree->right;
		}
		else{
			return 0;
		}
	}
}

int treeHeight(binaryTree* tree){
	int left = 0;
	int right = 0;
	if (tree->left){
		left += 1 + treeHeight(tree->left);
	}
	if (tree->right){
		right += 1 + treeHeight(tree->right);
	}
	return max(left, right);
}

void treePrint(binaryTree* tree){
	if (tree != NULL){
		treePrint(tree->left);
		printf("%s\n", tree->value);
		treePrint(tree->right);
	}
}