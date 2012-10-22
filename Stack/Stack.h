/*
 * Stack.h
 *
 *  Created on: 2012-10-22
 *      Author: Administrator
 */

#ifndef STACK_H_
#define STACK_H_

#include "../CommonFlag.h"


typedef struct{
	ElemType *base;
	ElemType *top;
	int capacity;
}ArrayStack;


extern Status initArrayStack(ArrayStack *S);
extern Status destroyArrayStack(ArrayStack *S);
extern Status clearArrayStack(ArrayStack *S);
extern int isArrayStackEmpty(const ArrayStack *S);
extern int lengthOfArrayStack(const ArrayStack *S);
extern Status pushArrayStack(ArrayStack *S, ElemType e);
extern Status popArrayStack(ArrayStack *S, ElemType *e);
extern Status topOfArrayStack(const ArrayStack *S, ElemType *e);



#endif /* STACK_H_ */
