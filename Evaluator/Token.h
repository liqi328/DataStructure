/*
 * Token.h
 *
 *  Created on: 2012-10-22
 *      Author: Administrator
 */

#ifndef TOKEN_H_
#define TOKEN_H_

#define ValueType int

typedef enum TokenType{UnKnown, NUMBER = 4, MINUS = '-', PLUS = '+', MUL = '*', DIV = '/'}TokenType;
typedef struct{
	TokenType type;
	ValueType value;
}Token;


extern int initToken(Token *t, int value);
extern int isOperator(const Token *t);
/*
TokenType getTokenType(const Token *t);
ValueType getTokenValue(const Token *t);
*/

#endif /* TOKEN_H_ */
