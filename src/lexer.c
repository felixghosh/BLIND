#include <stdio.h>
#include "token.h"
#define PROGSIZE 65536   //32 bits
#define MAXTOKENS  4096     //12 bits


token_t** lex(char* program, int length);

int main(){
    char program[PROGSIZE] = {0};
    int c;
    int i = 0;

    while((c = getchar()) != EOF)   //Read program
       program[i++] = c;

    printf("Program: %s\n", program);

    token_t** tokens = lex(program, i);

    return 0;
}

token_t** lex(char* program, int length){
    token_t** tokens = malloc(MAXTOKENS * sizeof(token_t*));
    return tokens;
}