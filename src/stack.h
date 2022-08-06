#include <stdlib.h>
#include "grammar.h"

#define STACKMAX 4096

typedef struct {
    unsigned top;
    item_t* items;
} stack_t;

stack_t* new_stack_t(){
    stack_t* s = malloc(sizeof(stack_t));
    s->top = 0;
    s->items = malloc(STACKMAX * sizeof(item_t))
    return s;
}

unsigned push(stack_t* s, item_t* i){
    (s->item + s->(++top)) = i;
    return top;
}

item_t* pop(stack_t* s){
    item_t* item = (s->items + s->top);
    (s->items + s->top) = NULL;
    s->top--;
    return  item;
}

item_t* peek(stack_t* s){
    item_t* item = (s->items + s->top);
    return  item;
}