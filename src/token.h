#ifndef TOKEN_H
#define TOKEN_H
#include <stdlib.h>

typedef struct {
    const char* token;
    const char* value;
} token_t;

token_t* new_token_t(const char* token, const char* value){
    token_t* t = malloc(sizeof(token_t));
    t->token = token;
    t->value = value;
    return t;
}

#endif