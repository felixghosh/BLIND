#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include "../../src/lexer.h"

int main(){
    char program[PROGSIZE] = {0};
    int c;
    int i = 0;

    while((c = getchar()) != EOF)   //Read program
       program[i++] = c;


    token_t** tokens = lex(program, i);
    token_t** t = tokens;
    while(*t){
        printf("%s ", (*t)->type);
        t++;
    }
    printf("\n");
    t = tokens;
    while(*t){
        printf("%s ", (*t)->value);
        t++;
    }
    
    return 0;
}