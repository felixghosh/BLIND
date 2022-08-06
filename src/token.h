#ifndef TOKEN_H
#define TOKEN_H


#define MAXSIZE 1024

typedef struct {
    char* type;
    char* value;
} token_t;

token_t* new_token_t(char* type, char* value);

#endif