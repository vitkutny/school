#include <stdlib.h>
#include <stdarg.h>
#include "set.h"

set* setCreate(){
	set* new = (set*)malloc(sizeof(set));
	new->value = NULL;
	new->next = NULL;
	return new;
}

set* setSearch(set* set, int value){
	if (set->value == value){
		return set;
	}
	else if (set->next){
		return setSearch(set->next, value);
	}
	else{
		return NULL;
	}
}

set* setInsert(set* s, int value){
	set* new;
	if (setSearch(s, value)){
		return NULL;
	}
	new = setCreate();
	new->value = value;
	new->next = setCreate();
	new->next->value = s->value;
	new->next->next = s->next;
	*s = *new;
	return s;
}

int setRemove(set* s, int value){
	set* found = setSearch(s, value);
	return found ? (*found = *(found->next)), 1 : 0;
}

void setPrint(set* set){
	if (set->value){
		printf("%d ", set->value);
		if (set->next){
			setPrint(set->next);
		}
	}
	else{
		printf("\n");
	}
}

set* setUnion(set* first, set* second){
	set* u = setCreate();
	while (first && first->value){
		setInsert(u, first->value);
		first = first->next;
	}
	while (second && second->value){
		setInsert(u, second->value);
		second = second->next;
	}
	return u;
}

set* setIntersection(set* first, set* second){
	set* i = setCreate();
	while (first && first->value){
		if (setSearch(second, first->value)){
			setInsert(i, first->value);
		}
		first = first->next;
	}
	while (second && second->value){
		if (setSearch(first, second->value)){
			setInsert(i, second->value);
		}
		second = second->next;
	}
	return i;
}

set* setDifference(set* first, set* second){
	set* d = setCreate();
	while (first && first->value){
		if (!setSearch(second, first->value)){
			setInsert(d, first->value);
		}
		first = first->next;
	}
	return d;
}

set* setProccess(char* operations, ...){
	set* result;
	set* second;
	int i = 0;
	va_list args;
	va_start(args, operations);
	result = va_arg(args, set*);
	while (operations[i] != '\0'){
		second = va_arg(args, set*);
		switch (operations[i]){
		case 'u':
			result = setUnion(result, second);
			break;
		case 'i':
			result = setIntersection(result, second);
			break;
		case 'd':
			result = setDifference(result, second);
			break;
		}
		i++;
	}
	va_end(args);
	return result;
}