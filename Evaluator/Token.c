/*
 * Token.c
 *
 *  Created on: 2012-10-22
 *      Author: Administrator
 */

#include <stdio.h>
#include "Token.h"

static int _makeType(Token *t){
	switch(t->value){
		case MINUS:
			t->type = MINUS;
			break;
		case PLUS:
			t->type = PLUS;
			break;
		case MUL:
			t->type = MUL;
			break;
		case DIV:
			t->type = DIV;
			break;
		default:
			t->type = UNKNOMN;
			break;
	}
	return 1;
}

int initToken(Token *t, TokenValueType value){
	t->value = value;
	if(t->type != NUMBER){
		_makeType(t);
	}
	return 1;
}

int isOperator(const Token *t){
	return t->type >= MUL ;
}

