all:
	bison -d P1.y
	flex P1.l
	gcc P1.tab.c lex.yy.c -lfl -o P1 -g

bison:
	bison -d P1.y

flex:
	flex P1.l

prog:
	gcc P1.tab.c lex.yy.c -lfl -o P1 

clean :
	rm P1.tab.*
	rm lex.yy.c
	rm P1

