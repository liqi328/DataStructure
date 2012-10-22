/*
 * MinStack.c
 *
 *  Created on: 2012-10-22
 *      Author: Administrator
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "MinStack.h"

#define DEFAULT_CAPACITY 20
#define DEFAULT_INCREAMENT 10


Status initMinStack(MinStack *S){
	assert(S);
	S->base = (MinElem *)malloc(DEFAULT_CAPACITY * sizeof(MinElem));
	if(!S->base){
		printf("Error: memory allocation failed.\n");
		exit(OVERFLOW);
	}
	S->top = S->base;
	S->capacity = DEFAULT_CAPACITY;
	return OK;
}
Status destroyMinStack(MinStack *S){
	return OK;
}

Status clearMinStack(MinStack *S){
	return OK;
}

int isMinStackEmpty(const MinStack *S){
	return OK;
}

int lengthOfMinStack(const MinStack *S){
	return OK;
}

Status pushMinStack(MinStack *S, MinElem e){
	assert(S);
	MinElem * newbase;
	if(S->top - S->base >= S->capacity){
		newbase = (MinElem *)realloc(S->base, (S->capacity + DEFAULT_INCREAMENT) * sizeof(MinElem));
		if(!newbase){
			printf("Error: memory allocation failed.\n");
			exit(OVERFLOW);
		}
		S->base = newbase;
		S->top = S->base + S->capacity;
		S->capacity += DEFAULT_INCREAMENT;
	}
/*
	if(S->top == S->base){
		e.min = e.data;
	}else{
		if(e.data <= (*(S->top - 1)).data){
			e.min = e.data;
		}else{
			e.min = (S->top -1)->min;
		}
	}*/
	e.min = (S->top == S->base ? e.min : (S->top - 1)->min);
	if(e.data < e.min)e.min = e.data;
	*S->top = e;
	++S->top;

	return OK;
}

Status popMinStack(MinStack *S, MinElem *e){
	assert(S);
	if(S->top == S->base){
		printf("Stack is empty.\n");
		return ERROR;
	}
	--S->top;
	*e = *S->top;
	return OK;
}

Status topOfMinStack(const MinStack *S, MinElem *e){
	assert(S);
	if((*S).top == (*S).base){
		printf("Stack is already empty.\n");
		return ERROR;
	}
	*e = *((*S).top - 1);
	return OK;
}

