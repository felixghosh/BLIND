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
    t->type = calloc(1, MAXSIZE);
    t->value = calloc(1, MAXSIZE);
    strcpy(t->type, type);
    strcpy(t->value, value);
    return t;
}

#endif