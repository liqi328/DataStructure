/*
 * Polynomial.h
 *
 *  Created on: 2012-10-21
 *      Author: Administrator
 */

#ifndef _POLYNOMIAL_H_
#define _POLYNOMIAL_H_

typedef struct{
	float coef; /* 系数 */
	int expn;   /* 指数 */
}Term, ElemType;

#include "../List/LinkedList.h"

typedef LinkedList Polynomial;

extern Status createPolyn(Polynomial *p);

extern Status destroyPolyn(Polynomial *p);

extern Status printPolyn(Polynomial p);

extern int lenghtOfPolyn(Polynomial p);

extern Status addPolyn(Polynomial p, Polynomial q);

extern Status subtractPolyn(Polynomial p, Polynomial q);

extern Status multiplyPolyn(Polynomial p, Polynomial q);

extern int comparePolyn(Term p, Term q);

#endif /* _POLYNOMIAL_H_ */
