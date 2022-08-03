#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include "token.h"


#define PROGSIZE 65536   //32 bits
#define MAXTOKENS  4096     //12 bits

short is_final[38] = {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1};

token_t** lex(char* program, int length){
    token_t** tokens = malloc(MAXTOKENS * sizeof(token_t*));
    int n_tokens, pos = 0;
    int current_state = 0;
    int last_final_state, last_final_pos = 0;
    bool match;

    while(pos < length){
        match = false;
        int c = program[pos++];
        //printf("pos: %d state: %d c: %d\n", pos, current_state, c);
        switch(current_state){
            case 0:
                if(c == 'i'){
                    current_state = 1;
                } else if(c == ';'){
                    current_state = 6;
                } else if(c == '='){
                    current_state = 7;
                } else if(c == '('){
                    current_state = 8;
                } else if(c == ')'){
                    current_state = 9;
                } else if(c == '{'){
                    current_state = 10;
                } else if(c == '}'){
                    current_state = 11;
                } else if(c == 'w'){
                    current_state = 12;
                } else if(c == 'r'){
                    current_state = 17;
                } else if(c == '='){
                    current_state = 23;
                } else if(c == '!'){
                    current_state = 25;
                } else if(c == '<'){
                    current_state = 27;
                } else if(c == '>'){
                    current_state = 29;
                } else if(c == '+'){
                    current_state = 31;
                } else if(c == '-'){
                    current_state = 32;
                } else if(c == '*'){
                    current_state = 33;
                } else if(c == '/'){
                    current_state = 34;
                } else if(c == '%'){
                    current_state = 35;
                } else if(isdigit(c)){
                    current_state = 36;
                } else if(isalpha(c)){
                    current_state = 37;
                } else if(isspace(c)){
                    last_final_pos++;
                    continue;
                } else{
                    printf("ILLEGAL CHARACTER ENCOUNTERED! c = %d\n", c);
                }
                break;

            case 1:
                if(c == 'f'){
                    current_state = 2;
                } else if(c == 'n'){
                    current_state = 4;
                } else if(isalnum(c)){
                    current_state = 3;
                } else {
                    match = true;
                }
                break;

            case 2:
                if(isalnum(c)){
                    current_state = 3;
                } else {
                    match = true;
                }
                break;

            case 3:
                if(isalnum(c)){
                    current_state = 3;
                } else {
                    match = true;
                }
                break;

            case 4:
                if(c == 't'){
                    current_state = 5;
                }else if(isalnum(c)){
                    current_state = 3;
                } else {
                    match = true;
                }
                break;

            case 5:
                if(isalnum(c)){
                    current_state = 3;
                } else {
                    match = true;
                }
                break;
            case 6:
                match = true;
                break;
            case 7:
                match = true;
                break;
            case 8:
                match = true;
                break;
            case 9:
                match = true;
                break;  
            case 10:
                match = true;
                break;  
            case 11:
                match = true;
                break;  
            case 12:
                if(c == 'h')
                    current_state = 13;
                else
                    match = true;
                break;  
            case 13:
                if(c == 'i')
                    current_state = 14;
                else
                    match = true;
                break;  
            case 14:
                if(c == 'l')
                    current_state = 15;
                else
                    match = true;
                break;  
            case 15:
                if(c == 'e')
                    current_state = 16;
                else
                    match = true;
                break;  
            case 16:
                match = true;
                break;
            //RETURN???
            case 23:
                if(c == '=')
                    current_state = 24;
                else
                    match = true;
                break;
            case 24:
                match = true;
                break;  
            case 25:
                if(c == '=')
                    current_state = 26;
                else{
                    printf("ERROR: Expected = after !\n");
                    exit(1);
                }
                break;
            case 27:
                if(c == '=')
                    current_state = 28;
                else
                    match = true;
                break;
            case 28:
                match = true;
                break;
            case 29:
                if(c == '=')
                    current_state = 30;
                else
                    match = true;
                break;
            case 30:
                match = true;
                break;
            case 31:
                match = true;
                break;
            case 32:
                match = true;
                break;
            case 33:
                match = true;
                break;
            case 34:
                match = true;
                break;
            case 35:
                match = true;
                break;
            case 36:
                if(isdigit(c))
                    current_state = 36;
                else
                    match = true;
                break;
            case 37:
                if(isalnum(c))
                    current_state = 3;
                else
                    match =  true;
                break;
            case 38:
                match = true;
                break;
               
        }

        //printf("%d\n", pos);
        if(pos == length)
            match = true;

        if(is_final[current_state])
                last_final_state = current_state;

        if(match){
            pos--;
            int len = pos - last_final_pos;
            
            char type[7] = {0};
            char value[1024] = {0};
            
            switch(last_final_state){
                case 1:
                    strcpy(type, "ID");
                    break;
                case 2:
                    strcpy(type, "IF");
                    break;
                case 3:
                    strcpy(type, "ID");
                    break;
                case 4:
                    strcpy(type, "ID");
                    break;
                case 5:
                    strcpy(type, "INT");
                    break;
                case 6:
                    strcpy(type, "SEMI");
                    break;
                case 7:
                    strcpy(type, "ASS");
                    break;
                case 8:
                    strcpy(type, "LPAREN");
                    break;
                case 9:
                    strcpy(type, "RPAREN");
                    break;
                case 10:
                    strcpy(type, "LBRACE");
                    break;
                case 11:
                    strcpy(type, "RBRACE");
                    break;
                case 12:
                    strcpy(type, "ID");
                    break;
                case 13:
                    strcpy(type, "ID");
                    break;
                case 14:
                    strcpy(type, "ID");
                    break;
                case 15:
                    strcpy(type, "ID");
                    break;
                case 16:
                    strcpy(type, "WHILE");
                    break;
                case 17:
                    strcpy(type, "ID");
                    break;
                case 18:
                    strcpy(type, "ID");
                    break;
                case 19:
                    strcpy(type, "ID");
                    break;
                case 20:
                    strcpy(type, "ID");
                    break;
                case 21:
                    strcpy(type, "ID");
                    break;
                case 22:
                    strcpy(type, "RET");
                    break;
                case 23:
                    strcpy(type, "ASS");
                    break;
                case 24:
                    strcpy(type, "EQ");
                    break;
                case 26:
                    strcpy(type, "NOTEQ");
                    break;
                case 27:
                    strcpy(type, "LT");
                    break;
                case 28:
                    strcpy(type, "LTE");
                    break;
                case 29:
                    strcpy(type, "GT");
                    break;
                case 30:
                    strcpy(type, "GTE");
                    break;
                case 31:
                    strcpy(type, "ADD");
                    break;
                case 32:
                    strcpy(type, "SUB");
                    break;
                case 33:
                    strcpy(type, "MUL");
                    break;
                case 34:
                    strcpy(type, "DIV");
                    break;
                case 35:
                    strcpy(type, "MOD");
                    break;
                case 36:
                    strcpy(type, "NUM");
                    break;
                case 37:
                    strcpy(type, "ID");
                    break;
                case 38:    //Whitespace
                    continue;
                default:
                    printf("ERROR, NO MATCH");
                    exit(1);
            }
            for(int i = 0; i < len; i++){
                value[i] = program[last_final_pos+i];
            }
            last_final_pos = pos;

            token_t* t = new_token_t(type, value);
            tokens[n_tokens++] = t;
            current_state = 0;
        }
        
    }
    return tokens;
}

int main(){
    char program[PROGSIZE] = {0};
    int c;
    int i = 0;

    while((c = getchar()) != EOF)   //Read program
       program[i++] = c;


    token_t** tokens = lex(program, i);
    while(*tokens){
        printf("%s ", (*tokens)->type);
        tokens++;
    }
    
    return 0;
}



/*
3 parse last char
*/