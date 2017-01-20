/* BISON FILE P1.y */

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define IDSIZE 1000
#define STRINGSIZE 1000000000
#define MAX_ARGS 1000

extern int yylex();
extern void yyerror(char *);

char* initString() {
	char* s = (char*) malloc(sizeof(char)*STRINGSIZE);
	return s;
}

typedef struct node {
	char* name;	
	char* args;
	char* repl;
	struct node* next;
} node;

node* HEAD = NULL;

void insert(char* id,char* arguments,char* replacement,int expr) {

	node* A = (node*) malloc(sizeof(node));
	A->name = (char*) malloc(sizeof(char)*IDSIZE);
	strcpy(A->name,id);
	A->args = (char*) malloc(sizeof(char)*STRINGSIZE);
	strcpy(A->args,arguments);
	A->repl = (char*) malloc(sizeof(char)*STRINGSIZE);
	if(expr) {
		strcpy(A->repl,"(");
		strcat(A->repl,replacement);
		strcat(A->repl,")");
	} else {
		strcpy(A->repl,replacement);
	}
	A->next = NULL;
	if(!HEAD) {
		HEAD = A;
	} else {
		A->next = HEAD;
		HEAD = A;
	}
}

node* query(char* id) {
	node* temp = HEAD;
	while(temp) {
		if(strcmp(temp->name,id) == 0) {
			return temp;
		}
		temp = temp->next;
	}
}

char *replaceString(char *str, char *original, char *replica)
{
    char* buffer = initString();
    char *p;
    char* orig = initString();
    strcpy(orig,original);
    char* rep = initString();
    strcpy(rep,replica);
    if(!(p = strstr(str, orig)))
    return str;
     
    strncpy(buffer, str, p-str);
    buffer[p-str] = '\0';
     
    sprintf(buffer+(p-str), "%s%s", rep, p+strlen(orig));
     
    return buffer;
}

char* replacement(node* N,char* repArgs) {
	char* temp;
	char sep[] = ",";
	char* token;
	int argc = 0;
	char* argv[MAX_ARGS];
	token = strtok (N->args, sep);
	while (token != NULL)
	{
	  	argv[argc++] = (char*) malloc(sizeof(char)*IDSIZE);
	  	strcpy(argv[argc-1],token);
	    token = strtok (NULL, sep);
	}
	int i=0;
	char* repargv[MAX_ARGS];
	int repargc = 0;
	token = strtok (repArgs, sep);
	while (token != NULL)
	{
	  	repargv[repargc++] = (char*) malloc(sizeof(char)*IDSIZE);
	  	strcpy(repargv[repargc-1],token);
	    token = strtok (NULL, sep);
	}
	if( argc != repargc) {
		// printf("%s used (declared in #define), but insufficient arguments provided!\n",N->name);
		printf("// Failed to parse macrojava code.\n");
		exit(0);
		return "";
	}
	temp = N->repl;
	while(argc--) {
		temp = replaceString(temp,argv[argc],repargv[argc]);
	}
	char* S = initString();
	strcpy(S,temp);
	return S;
}

char* REP (char* id,char* args) {
	node* N = query(id);
	if ( N == NULL ) { // Case when the #define is not declared
		printf("// Failed to parse macrojava code.\n");
		exit(0);
	}
	char* t =  replacement(N,args);
	return t;
}

%}

%union {
	char* var_name;
}
%expect 11
%token <var_name>  INTEGER LENGTH
%token <var_name> IDENTIFIER PLUS MINUS MULT DIV ASSIGN CLASS PUBLIC STATIC VOID MAIN DEFINE PRINTLN LEFT RIGHT LEFTCURL RIGHTCURL SEMICOLON COMMA STRING ARR BOOL INT THIS TRUE FALSE LEFTD	RIGHTD NEW NOT ANDOP OROP NE LTE DOT RETURN IF ELSE WHILE EXTENDS

%left MINUS PLUS
%left MULT DIV

%right ELSE

%type <var_name> Statements
%type <var_name> expression
%type <var_name> Goal
%type <var_name> MainClass
%type <var_name> arguments
%type <var_name> Statement
%type <var_name> Def
%type <var_name> MacroDefinition 
%type <var_name> MacroDefExpression matched unmatched otherStatement
%type <var_name> MacroDefStatement PrimaryExpression argExp Type funcArg
%type <var_name> typeDec Initialization Methods TypeDeclaration MethodDeclaration 

%start Goal

%%

Goal : Def  MainClass typeDec {printf("%s\n%s",$2,$3);}


Def : Def MacroDefinition {$$= "";} 
		| %empty { $$ = "";}

typeDec : typeDec TypeDeclaration  { $$ = initString();sprintf($$,"%s%s\n",$1,$2);}
				| %empty { $$ = "";}

Statements : Statement Statements { $$=initString();sprintf($$,"%s\n%s",$1,$2);}
					 | %empty { $$= "";}

Statement : matched { $$ = $1;}
					| unmatched { $$ = $1;}

matched : IF LEFT expression RIGHT matched ELSE matched { $$ = initString(); sprintf($$,"if (%s) %s else %s",$3,$5,$7);}
				| otherStatement	{ $$ = $1;}

unmatched : IF LEFT expression RIGHT Statement { $$ = initString(); sprintf($$,"if (%s) %s",$3,$5);}
					| IF LEFT expression RIGHT matched ELSE unmatched { $$ = initString(); sprintf($$,"if (%s) %s else %s",$3,$5,$7);}


otherStatement  : PRINTLN LEFT expression RIGHT SEMICOLON { $$ = initString(); sprintf($$,"System.out.println(%s);",$3);} 
					 | LEFTCURL Statements RIGHTCURL { $$ = initString();sprintf($$,"{\n%s\n}",$2);} 
					 | IDENTIFIER ASSIGN expression SEMICOLON { $$ = initString(); sprintf($$,"%s = %s;",$1,$3);}
					 | IDENTIFIER LEFTD expression RIGHTD ASSIGN expression SEMICOLON { $$ = initString(); sprintf($$,"%s [%s] =  %s;",$1,$3,$6);}
					 | WHILE LEFT expression RIGHT Statement { $$ = initString(); sprintf($$,"while (%s) %s",$3,$5);}
					 | IDENTIFIER LEFT argExp RIGHT SEMICOLON {$$ = REP($1,$3);}

MacroDefinition	:	MacroDefExpression
								|	MacroDefStatement

MacroDefStatement	 :	DEFINE IDENTIFIER LEFT arguments RIGHT LEFTCURL Statements  RIGHTCURL {
									insert($2,$4,$7,0);				
}

MacroDefExpression :	DEFINE IDENTIFIER LEFT arguments RIGHT LEFT expression RIGHT 
											{
												insert($2,$4,$7,1);
											}

arguments : IDENTIFIER COMMA arguments	{ $$ = strcat($1,","); $$ = strcat($$,$3);}
					| IDENTIFIER { $$ = $1;}
					| %empty	{ char* temp= "";$$ = temp;}


MainClass : CLASS IDENTIFIER LEFTCURL PUBLIC STATIC VOID MAIN LEFT STRING ARR IDENTIFIER RIGHT LEFTCURL PRINTLN LEFT expression RIGHT SEMICOLON RIGHTCURL RIGHTCURL {
	$$ = initString();sprintf($$,"class %s {\n\tpublic static void main ( String [] %s ) {\n\t\tSystem.out.println(%s);\n\t}\n}\n",$2,$11,$16);	
} 

expression	:	PrimaryExpression ANDOP PrimaryExpression { $$ = initString(); sprintf($$,"%s && %s",$1,$3); }
						|	PrimaryExpression OROP PrimaryExpression { $$ = initString(); sprintf($$,"%s || %s",$1,$3); }
						|	PrimaryExpression NE PrimaryExpression { $$ = initString(); sprintf($$,"%s != %s",$1,$3); }
						|	PrimaryExpression LTE PrimaryExpression { $$ = initString(); sprintf($$,"%s <= %s",$1,$3); }
						|	PrimaryExpression PLUS PrimaryExpression { $$ = initString(); sprintf($$,"%s + %s",$1,$3); }
						|	PrimaryExpression MINUS PrimaryExpression { $$ = initString(); sprintf($$,"%s - %s",$1,$3); }
						|	PrimaryExpression MULT PrimaryExpression { $$ = initString(); sprintf($$,"%s * %s",$1,$3); }
						|	PrimaryExpression DIV PrimaryExpression { $$ = initString(); sprintf($$,"%s / %s",$1,$3); }
						|	PrimaryExpression LEFTD PrimaryExpression RIGHTD { $$ = initString(); sprintf($$,"%s [%s]",$1,$3); }
						|	PrimaryExpression DOT LENGTH { $$ = initString(); sprintf($$,"%s.length",$1); }
						|	PrimaryExpression { $$ = $1; }
						|	PrimaryExpression DOT IDENTIFIER LEFT argExp RIGHT { $$ = initString(); sprintf($$,"%s.%s(%s)",$1,$3,$5); }
						| IDENTIFIER LEFT argExp RIGHT {$$ = REP($1,$3);}


argExp : expression COMMA argExp { $$= initString(); sprintf($$,"%s , %s",$1,$3);}
			 | expression { $$ =  $1;}
			 | %empty { $$ = "";}


PrimaryExpression	:	INTEGER	{ $$ = $1;}
									|	TRUE		{ $$ = "true";}
									|	FALSE		{ $$ = "false";}
									|	IDENTIFIER	{ $$ = $1;}
									|	THIS	{$$ = "this";}
									|	NEW INT LEFTD expression RIGHTD { $$ = initString(); sprintf($$,"new int [%s]",$4);}
									|	NEW IDENTIFIER LEFT RIGHT { $$ = initString();sprintf($$,"new %s()",$2);}
									|	NOT expression { $$ = initString();sprintf($$,"! %s",$2);}
									|	LEFT expression RIGHT { $$ = initString();sprintf($$,"( %s )",$2);}

Type	:	INT ARR { $$ = "int []";}
			|	BOOL	{ $$ = "boolean";}
			|	INT { $$ = "int"; }
			|	IDENTIFIER { $$ = $1;}

Initialization : Initialization Type IDENTIFIER SEMICOLON  { $$ = initString(); sprintf($$,"%s %s %s;\n",$1,$2,$4);}
								 |	%empty { $$ = "";}

Methods : Methods MethodDeclaration  { $$ = initString(); sprintf($$,"%s%s\n",$1,$2);}
				|	%empty	{$$ = "";}

TypeDeclaration	:	CLASS IDENTIFIER LEFTCURL Initialization Methods RIGHTCURL { $$ = initString();sprintf($$,"class %s {\n%s %s \n}\n",$2,$4,$5);}
								|	CLASS IDENTIFIER EXTENDS IDENTIFIER LEFTCURL Initialization Methods RIGHTCURL {
								$$ = initString(); sprintf($$,"class %s extends %s {\n %s %s\n}\n",$2,$4,$6,$7);
								}

MethodDeclaration	:	PUBLIC Type IDENTIFIER LEFT funcArg RIGHT LEFTCURL Initialization Statements RETURN expression SEMICOLON RIGHTCURL { $$ = initString(); sprintf($$,"public %s %s ( %s ) { \n %s %s \nreturn %s;\n}",$2,$3,$5,$8,$9,$11);}

funcArg : Type IDENTIFIER { $$ = initString(); sprintf($$,"%s %s",$1,$2);}
				| Type IDENTIFIER COMMA funcArg { $$ = initString(); sprintf($$,"%s %s, %s",$1,$2,$4);}
				| %empty { $$ = "";}


%%

