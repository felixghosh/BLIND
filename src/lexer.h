#ifndef LEXER_H
#define LEXER_H

#include "token.h"
#define PROGSIZE 65536   //32 bits
#define MAXTOKENS  4096     //12 bits

token_t** lex(char* program, int length);

#endif