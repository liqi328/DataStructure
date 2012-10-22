/*
 * Token.c
 *
 *  Created on: 2012-10-22
 *      Author: Administrator
 */

#include <stdio.h>
#include "Token.h"

int initToken(Token *t, int value){

}

int isOperator(const Token *t){
	return t->type >= TokeyType('-');
}

