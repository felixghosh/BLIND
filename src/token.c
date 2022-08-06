#include <stdlib.h>
#include "token.h"

token_t* new_token_t(char* type, char* value){
    token_t* t = malloc(sizeof(token_t));
    t->type = type;
    t->value = value;
    return t;
}