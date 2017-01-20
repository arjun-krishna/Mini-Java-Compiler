  //FLEX FILE P1.l 

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "P1.tab.h" // the output of bison on P1.y
void yyerror(char*); 
int yyparse(void); 
%}

%%
[0-9]+   { 
           // yylval.int_val = atoi(yytext);
           yylval.var_name = (char*) malloc(sizeof(char)*20);
           strcpy(yylval.var_name,yytext);
           return INTEGER; 
         }
"/"       return DIV;
"*"       return MULT;
"+"       return PLUS;
"-"       return MINUS;
"="       return ASSIGN;
"{"				return LEFTCURL;
"}"				return RIGHTCURL;
"!"				return NOT;
"("				return LEFT;
")"				return RIGHT;
"["				return LEFTD;
"]"				return RIGHTD;
";"				return SEMICOLON;
","				return COMMA;
"&&"			return ANDOP;
"||"			return OROP;
"!="			return NE;
"<="			return LTE;
(\/\/.*\n) ;
[ \t\n\r]+    ;   //do nothing on whitespace

"#define" return DEFINE;
"new"			return NEW;
"true"		return TRUE;
"false"		return FALSE;
"this"		return THIS;
"class" 	return CLASS;
"public"	return PUBLIC;
"static"  return STATIC;
"void"		return VOID;
"main"		return MAIN;
"return"	return RETURN;
"length"  return LENGTH;
"if"			return IF;
"else"		return ELSE;
"while"		return WHILE;
"extends"	return EXTENDS;
"System.out.println" return PRINTLN;


"String"	return STRING;
"int"			return INT;
"boolean"	return BOOL;

[[][ ]*[]]  return ARR;

[A-Za-z_][A-Za-z0-9_]*   {
                           yylval.var_name = (char*) malloc(sizeof(char)*strlen(yytext)+3);
                           strcpy(yylval.var_name,yytext);
                           //printf("\nsaw - %s\n",yytext);
                           return IDENTIFIER;
                          }
<<EOF>>     { return 0; } 
.           return DOT;

%%

void yyerror(char* str) { printf("// Failed to parse macrojava code.\n"); }

int yywrap(void) { return 1; }

int main(void) {
  yyparse();  
}
