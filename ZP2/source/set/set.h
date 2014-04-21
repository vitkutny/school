#ifndef _INC_SET
#define _INC_SET
typedef struct set {
	int value; struct set* next;
} set;

set* setCreate();
set* setInsert(set*, int);
int setRemove(set*, int);
void setPrint(set*);
set* setSearch(set*, int);
set* setUnion(set*, set*);
set* setIntersection(set*, set*);
set* setDifference(set*, set*);
set* setProccess(char*, ...);
#endif