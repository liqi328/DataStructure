/*
 * MinStack.h
 *
 *  Created on: 2012-10-22
 *      Author: Administrator
 */

#ifndef MINSTACK_H_
#define MINSTACK_H_

#include "../CommonFlag.h"

typedef struct{
	int data;
	int min;
}MinElem;

typedef struct{
	MinElem *base;
	MinElem *top;
	int capacity;
}MinStack;

extern Status initMinStack(MinStack *S);
extern Status destroyMinStack(MinStack *S);
extern Status clearMinStack(MinStack *S);
extern int isMinStackEmpty(const MinStack *S);
extern int lengthOfMinStack(const MinStack *S);
extern Status pushMinStack(MinStack *S, MinElem e);
extern Status popMinStack(MinStack *S, MinElem *e);
extern Status topOfMinStack(const MinStack *S, MinElem *e);

#endif /* MINSTACK_H_ */
