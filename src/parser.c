#include <stdio.h>
#include "grammar.h"
#include "lexer.h"



int main(){
    char program[PROGSIZE] = {0};
    int c;
    int i = 0;

    while((c = getchar()) != EOF)   //Read program
       program[i++] = c;


    token_t** tokens = lex(program, i);
    token_t** t = tokens;

    return 0;
}