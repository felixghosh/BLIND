#ifndef TOKEN_H
#define TOKEN_H
#include <stdlib.h>

#define MAXSIZE 1024

typedef struct {
    char* type;
    char* value;
} token_t;

token_t* new_token_t(char* type, char* value){
    token_t* t = malloc(sizeof(token_t));
    t->type = type;
    t->value = value;
    return t;
}

#endif