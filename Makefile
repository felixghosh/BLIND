token:
	cc -c src/token.c -o out/token.o

lexer: token
	cc -c src/lexer.c -o out/lexer.o

parser: lexer


test:
	./tests/test.sh

test-lexer: lexer 
	cc tests/lexer/test_lexer.c out/token.o out/lexer.o -o out/test_lexer -g
	./out/test_lexer