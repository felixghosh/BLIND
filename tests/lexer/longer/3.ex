cc src/lexer.c -o out/lexer -g
./out/lexer
INT ID ASS NUM ADD NUM SEMI IF LPAREN ID EQ NUM RPAREN LBRACE ID ASS NUM SEMI RBRACE 
int a = 5 + 5 ; if ( a == 10 ) { a = 0 ; } 