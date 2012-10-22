/*
 * Polynomial.c
 *
 *  Created on: 2012-10-21
 *      Author: Administrator
 */

#include <stdio.h>
#include <assert.h>
#include "Polynomial.h"

Status createPolyn(Polynomial *p);

Status destroyPolyn(Polynomial *p);

Status printPolyn(Polynomial p){
	assert(p);
	Polynomial q = p->next;

}

int lenghtOfPolyn(Polynomial p);

Status addPolyn(Polynomial p, Polynomial q);

Status subtractPolyn(Polynomial p, Polynomial q);

Status multiplyPolyn(Polynomial p, Polynomial q);

/* 比较多项式的 相的指数是否相同*/
int comparePolyn(Term p, Term q){
	if(p.expn > q.expn)return 1;
	else if(p.expn < q.expn)return -1;
	return 0;
}
