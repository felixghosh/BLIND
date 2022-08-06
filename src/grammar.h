#ifndef GRAMMAR_H
#define GRAMMAR_H
#include <stdlib.h>
#include "token.h"

typedef struct {
    char* type;
} nonterm_t;

typedef struct{
    token_t* t;
    nonterm_t* n;
} item_t;

typedef struct {
    item_t** items;
} prod_rule_t;

nonterm_t* new_nonterm_t(char* type){
    nonterm_t* n = malloc(sizeof(nonterm_t));
    n->type = type;
    return n;
}

item_t* new_item_t(token_t* t, nonterm_t* n){
    item_t* i = malloc(sizeof(item_t));
    i->t = t;
    i->n = n;
    return n;
}

prod_rule_t* new_prod_rule_t(item_t** items){
    prod_rule_t* p = malloc(sizeof(prod_rule_t));
    p->items = items;
    return p;
}

#endif