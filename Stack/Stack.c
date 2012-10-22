/*
 * Stack.c
 *
 *  Created on: 2012-10-22
 *      Author: Administrator
 */

#include <stdio.h>
#include <assert.h>
#include "Stack.h"

#define DEFAULT_CAPACITY 20
#define DEFAULT_INCREAMENT 10

Status initArrayStack(ArrayStack *S){
	assert(S);
	(*S).base = (ElemType *)malloc(DEFAULT_CAPACITY * sizeof(ElemType));
	if(!(*S).base){
		printf("Error: memory allocation failed.\n");
		exit(OVERFLOW);
	}
	(*S).top = (*S).base;
	(*S).capacity = DEFAULT_CAPACITY;
	return OK;
}

Status destroyArrayStack(ArrayStack *S){
	assert(S);
	free((*S).base);
	free(S);
	S = NULL;
	return OK;
}

Status clearArrayStack(ArrayStack *S){
	assert(S);
	(*S).top = (*S).base;
	return OK;
}
int isArrayStackEmpty(const ArrayStack *S){
	assert(S);
	return (*S).top == (*S).base;
}

int lengthOfArrayStack(const ArrayStack *S){
	assert(S);
	return (*S).top - (*S).base;
}

Status pushArrayStack(ArrayStack *S, ElemType e){
	assert(S);
	ElemType *newbase;
	if((*S).top - (*S).base >= (*S).capacity){
		newbase = (ElemType *)realloc((*S).base, ((*S).capacity + DEFAULT_INCREAMENT) * sizeof(ElemType));
		if(!newbase){
			printf("Error: memory allocation failed.\n");
			exit(OVERFLOW);
		}
		(*S).base = newbase;
		(*S).top = (*S).base + (*S).capacity;
		(*S).capacity += DEFAULT_INCREAMENT;
	}
	*(*S).top = e;
	++(*S).top;
	return OK;
}
Status popArrayStack(ArrayStack *S, ElemType *e){
	assert(S);
	if((*S).top == (*S).base){
		printf("Error: Stack is already empty.\n");
		return ERROR;
	}
	--(*S).top;
	*e = *(*S).top;
	return OK;
}

Status topOfArrayStack(const ArrayStack *S, ElemType *e){
	assert(S);
	if((*S).top == (*S).base){
		printf("Error: Stack is already empty.\n");
		return ERROR;
	}
	*e = *((*S).top - 1);
	return OK;
}
