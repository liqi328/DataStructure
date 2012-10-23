/*
 * Token.h
 *
 *  Created on: 2012-10-22
 *      Author: Administrator
 */

#ifndef TOKEN_H_
#define TOKEN_H_

#define TokenValueType int
/* or
#define TokenValueType double
*/

typedef enum TokenType{NULL_TOKEN = 0,UNKNOMN = 1, NUMBER = 4, MINUS = '-', PLUS = '+', MUL = '*', DIV = '/'}TokenType;
typedef struct{
	TokenType type;
	TokenValueType value;
}Token;


extern int initToken(Token *t, TokenValueType value);
extern int isOperator(const Token *t);

#endif /* TOKEN_H_ */
