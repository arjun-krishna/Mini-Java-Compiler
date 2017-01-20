/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 3 "P1.y" /* yacc.c:339  */

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


#line 194 "P1.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "P1.tab.h".  */
#ifndef YY_YY_P1_TAB_H_INCLUDED
# define YY_YY_P1_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INTEGER = 258,
    LENGTH = 259,
    IDENTIFIER = 260,
    PLUS = 261,
    MINUS = 262,
    MULT = 263,
    DIV = 264,
    ASSIGN = 265,
    CLASS = 266,
    PUBLIC = 267,
    STATIC = 268,
    VOID = 269,
    MAIN = 270,
    DEFINE = 271,
    PRINTLN = 272,
    LEFT = 273,
    RIGHT = 274,
    LEFTCURL = 275,
    RIGHTCURL = 276,
    SEMICOLON = 277,
    COMMA = 278,
    STRING = 279,
    ARR = 280,
    BOOL = 281,
    INT = 282,
    THIS = 283,
    TRUE = 284,
    FALSE = 285,
    LEFTD = 286,
    RIGHTD = 287,
    NEW = 288,
    NOT = 289,
    ANDOP = 290,
    OROP = 291,
    NE = 292,
    LTE = 293,
    DOT = 294,
    RETURN = 295,
    IF = 296,
    ELSE = 297,
    WHILE = 298,
    EXTENDS = 299
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 131 "P1.y" /* yacc.c:355  */

	char* var_name;

#line 283 "P1.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_P1_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 298 "P1.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   167

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  174

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   159,   159,   162,   163,   165,   166,   168,   169,   171,
     172,   174,   175,   177,   178,   181,   182,   183,   184,   185,
     186,   188,   189,   191,   195,   200,   201,   202,   205,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   224,   225,   226,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   239,   240,   241,   242,   244,   245,
     247,   248,   250,   251,   255,   257,   258,   259
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "LENGTH", "IDENTIFIER",
  "PLUS", "MINUS", "MULT", "DIV", "ASSIGN", "CLASS", "PUBLIC", "STATIC",
  "VOID", "MAIN", "DEFINE", "PRINTLN", "LEFT", "RIGHT", "LEFTCURL",
  "RIGHTCURL", "SEMICOLON", "COMMA", "STRING", "ARR", "BOOL", "INT",
  "THIS", "TRUE", "FALSE", "LEFTD", "RIGHTD", "NEW", "NOT", "ANDOP",
  "OROP", "NE", "LTE", "DOT", "RETURN", "IF", "ELSE", "WHILE", "EXTENDS",
  "$accept", "Goal", "Def", "typeDec", "Statements", "Statement",
  "matched", "unmatched", "otherStatement", "MacroDefinition",
  "MacroDefStatement", "MacroDefExpression", "arguments", "MainClass",
  "expression", "argExp", "PrimaryExpression", "Type", "Initialization",
  "Methods", "TypeDeclaration", "MethodDeclaration", "funcArg", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299
};
# endif

#define YYPACT_NINF -115

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-115)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -115,    13,    50,  -115,    21,    27,  -115,  -115,  -115,  -115,
      26,    49,    61,    63,    68,    71,  -115,    66,    57,    72,
       5,    70,    68,    44,  -115,    80,    77,  -115,    53,    14,
       9,    75,    78,  -115,    79,    53,  -115,  -115,  -115,    18,
      53,    81,     2,    12,    83,    14,    84,    86,    85,    14,
    -115,  -115,  -115,  -115,  -115,    73,    94,     3,  -115,    88,
      53,    89,    87,    76,  -115,  -115,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    65,    53,    53,    53,    53,
      92,    53,    53,  -115,  -115,  -115,    93,     9,  -115,  -115,
       9,    91,    96,    90,  -115,    95,    53,  -115,  -115,  -115,
    -115,  -115,    97,  -115,  -115,  -115,  -115,  -115,    99,   108,
     112,   101,   115,  -115,   116,   117,  -115,   105,     8,   132,
      53,  -115,  -115,   106,  -115,    53,  -115,   118,   131,   120,
      14,    14,   125,  -115,   126,  -115,  -115,   127,  -115,    53,
    -115,  -115,   102,  -115,     9,   128,  -115,   129,    14,   142,
     130,   133,  -115,  -115,  -115,   134,   135,   136,     9,  -115,
      53,  -115,     1,   137,    12,   113,   138,    53,   140,   141,
     143,   144,  -115,  -115
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     1,     0,     0,     3,    22,    21,     6,
       0,     0,     2,     0,    27,     0,     5,     0,    26,     0,
       0,     0,    27,     0,    59,     0,     0,    25,     0,     8,
      61,     0,     0,    45,    48,     0,    49,    46,    47,     0,
       0,     0,    39,     0,     0,     8,     0,     0,     0,     8,
       9,    10,    12,    57,    55,    56,     0,     0,    59,     0,
      44,     0,     0,     0,    52,    24,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    44,     0,     0,
       0,     0,     0,    23,     7,    54,     0,     0,    62,    60,
      61,     0,    43,     0,    53,     0,     0,    48,    33,    34,
      35,    36,     0,    29,    30,    31,    32,    38,     0,     0,
       0,     0,     0,    16,     0,     0,    58,     0,     0,     0,
      44,    41,    51,     0,    37,    44,    17,     0,     0,     0,
       0,     0,     0,    63,     0,    42,    50,     0,    20,     0,
      15,    13,     9,    19,    67,     0,    40,     0,     0,     0,
       0,     0,    18,    11,    14,    65,     0,     0,    67,    59,
       0,    66,     8,     0,    57,     0,     0,     0,     0,     0,
       0,     0,    28,    64
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -115,  -115,  -115,  -115,   -44,  -114,   -71,     4,  -115,  -115,
    -115,  -115,   145,  -115,   -28,   -73,    54,   -84,   -56,    69,
    -115,  -115,     0
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    12,    48,    49,    50,    51,    52,     6,
       7,     8,    19,     9,    92,    93,    42,    56,    30,    57,
      16,    89,   150
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      41,    80,    90,   117,   110,    84,   164,    61,    66,    67,
      68,    69,    64,     3,    53,    87,   141,   143,    44,    43,
      87,    45,    76,    62,    88,    24,    10,    54,    55,   133,
      77,    44,    11,    70,    45,    54,    55,    71,    72,    73,
      74,    75,    46,    78,    47,    63,    13,   135,   109,    25,
     111,   112,   137,   114,   115,    46,    33,    47,    34,   142,
     149,     4,    28,    33,    29,    97,     5,    14,   123,   107,
     108,    35,    15,    18,   149,    17,    20,   153,    35,    21,
      22,    36,    37,    38,    26,    31,    39,    40,    36,    37,
      38,    23,    32,    39,    40,    58,    59,    60,    85,    86,
      65,    79,    81,   162,    82,    95,    83,    96,    94,   121,
     132,   147,    91,   113,   122,   116,   119,   125,   165,   120,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   124,
     126,   127,   163,   128,   129,   130,   131,   134,   136,   169,
     138,   139,   140,   144,   148,   145,   146,   155,   151,   156,
     157,   152,   154,   167,   160,   159,   166,   158,   161,   118,
     168,   170,     0,   171,   172,   173,     0,    27
};

static const yytype_int16 yycheck[] =
{
      28,    45,    58,    87,    77,    49,     5,    35,     6,     7,
       8,     9,    40,     0,     5,    12,   130,   131,    17,     5,
      12,    20,    10,     5,    21,    20,     5,    26,    27,    21,
      18,    17,     5,    31,    20,    26,    27,    35,    36,    37,
      38,    39,    41,    31,    43,    27,    20,   120,    76,    44,
      78,    79,   125,    81,    82,    41,     3,    43,     5,   130,
     144,    11,    18,     3,    20,     5,    16,    18,    96,     4,
       5,    18,    11,     5,   158,    12,     5,   148,    18,    13,
      23,    28,    29,    30,    14,     5,    33,    34,    28,    29,
      30,    19,    15,    33,    34,    20,    18,    18,    25,     5,
      19,    18,    18,   159,    18,    18,    21,    31,    19,    19,
       5,   139,    24,    21,    19,    22,    25,    18,   162,    23,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    32,
      22,    19,   160,    32,    19,    19,    19,     5,    32,   167,
      22,    10,    22,    18,    42,    19,    19,     5,    20,    19,
      17,    22,   148,    40,    18,    20,    19,    23,   158,    90,
      22,    21,    -1,    22,    21,    21,    -1,    22
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    46,    47,     0,    11,    16,    54,    55,    56,    58,
       5,     5,    48,    20,    18,    11,    65,    12,     5,    57,
       5,    13,    23,    19,    20,    44,    14,    57,    18,    20,
      63,     5,    15,     3,     5,    18,    28,    29,    30,    33,
      34,    59,    61,     5,    17,    20,    41,    43,    49,    50,
      51,    52,    53,     5,    26,    27,    62,    64,    20,    18,
      18,    59,     5,    27,    59,    19,     6,     7,     8,     9,
      31,    35,    36,    37,    38,    39,    10,    18,    31,    18,
      49,    18,    18,    21,    49,    25,     5,    12,    21,    66,
      63,    24,    59,    60,    19,    18,    31,     5,    61,    61,
      61,    61,    61,    61,    61,    61,    61,     4,     5,    59,
      60,    59,    59,    21,    59,    59,    22,    62,    64,    25,
      23,    19,    19,    59,    32,    18,    22,    19,    32,    19,
      19,    19,     5,    21,     5,    60,    32,    60,    22,    10,
      22,    50,    51,    50,    18,    19,    19,    59,    42,    62,
      67,    20,    22,    51,    52,     5,    19,    17,    23,    20,
      18,    67,    63,    59,     5,    49,    19,    40,    22,    59,
      21,    22,    21,    21
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    48,    49,    49,    50,
      50,    51,    51,    52,    52,    53,    53,    53,    53,    53,
      53,    54,    54,    55,    56,    57,    57,    57,    58,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    60,    60,    60,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    62,    62,    62,    62,    63,    63,
      64,    64,    65,    65,    66,    67,    67,    67
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     0,     2,     0,     2,     0,     1,
       1,     7,     1,     5,     7,     5,     3,     4,     7,     5,
       5,     1,     1,     8,     8,     3,     1,     0,    20,     3,
       3,     3,     3,     3,     3,     3,     3,     4,     3,     1,
       6,     4,     3,     1,     0,     1,     1,     1,     1,     1,
       5,     4,     2,     3,     2,     1,     1,     1,     4,     0,
       2,     0,     6,     8,    13,     2,     4,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 159 "P1.y" /* yacc.c:1646  */
    {printf("%s\n%s",(yyvsp[-1].var_name),(yyvsp[0].var_name));}
#line 1485 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 162 "P1.y" /* yacc.c:1646  */
    {(yyval.var_name)= "";}
#line 1491 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 163 "P1.y" /* yacc.c:1646  */
    { (yyval.var_name) = "";}
#line 1497 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 165 "P1.y" /* yacc.c:1646  */
    { (yyval.var_name) = initString();sprintf((yyval.var_name),"%s%s\n",(yyvsp[-1].var_name),(yyvsp[0].var_name));}
#line 1503 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 166 "P1.y" /* yacc.c:1646  */
    { (yyval.var_name) = "";}
#line 1509 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 168 "P1.y" /* yacc.c:1646  */
    { (yyval.var_name)=initString();sprintf((yyval.var_name),"%s\n%s",(yyvsp[-1].var_name),(yyvsp[0].var_name));}
#line 1515 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 169 "P1.y" /* yacc.c:1646  */
    { (yyval.var_name)= "";}
#line 1521 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 171 "P1.y" /* yacc.c:1646  */
    { (yyval.var_name) = (yyvsp[0].var_name);}
#line 1527 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 172 "P1.y" /* yacc.c:1646  */
    { (yyval.var_name) = (yyvsp[0].var_name);}
#line 1533 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 174 "P1.y" /* yacc.c:1646  */
    { (yyval.var_name) = initString(); sprintf((yyval.var_name),"if (%s) %s else %s",(yyvsp[-4].var_name),(yyvsp[-2].var_name),(yyvsp[0].var_name));}
#line 1539 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 175 "P1.y" /* yacc.c:1646  */
    { (yyval.var_name) = (yyvsp[0].var_name);}
#line 1545 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 177 "P1.y" /* yacc.c:1646  */
    { (yyval.var_name) = initString(); sprintf((yyval.var_name),"if (%s) %s",(yyvsp[-2].var_name),(yyvsp[0].var_name));}
#line 1551 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 178 "P1.y" /* yacc.c:1646  */
    { (yyval.var_name) = initString(); sprintf((yyval.var_name),"if (%s) %s else %s",(yyvsp[-4].var_name),(yyvsp[-2].var_name),(yyvsp[0].var_name));}
#line 1557 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 181 "P1.y" /* yacc.c:1646  */
    { (yyval.var_name) = initString(); sprintf((yyval.var_name),"System.out.println(%s);",(yyvsp[-2].var_name));}
#line 1563 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 182 "P1.y" /* yacc.c:1646  */
    { (yyval.var_name) = initString();sprintf((yyval.var_name),"{\n%s\n}",(yyvsp[-1].var_name));}
#line 1569 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 183 "P1.y" /* yacc.c:1646  */
    { (yyval.var_name) = initString(); sprintf((yyval.var_name),"%s = %s;",(yyvsp[-3].var_name),(yyvsp[-1].var_name));}
#line 1575 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 184 "P1.y" /* yacc.c:1646  */
    { (yyval.var_name) = initString(); sprintf((yyval.var_name),"%s [%s] =  %s;",(yyvsp[-6].var_name),(yyvsp[-4].var_name),(yyvsp[-1].var_name));}
#line 1581 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 185 "P1.y" /* yacc.c:1646  */
    { (yyval.var_name) = initString(); sprintf((yyval.var_name),"while (%s) %s",(yyvsp[-2].var_name),(yyvsp[0].var_name));}
#line 1587 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 186 "P1.y" /* yacc.c:1646  */
    {(yyval.var_name) = REP((yyvsp[-4].var_name),(yyvsp[-2].var_name));}
#line 1593 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 191 "P1.y" /* yacc.c:1646  */
    {
									insert((yyvsp[-6].var_name),(yyvsp[-4].var_name),(yyvsp[-1].var_name),0);				
}
#line 1601 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 196 "P1.y" /* yacc.c:1646  */
    {
												insert((yyvsp[-6].var_name),(yyvsp[-4].var_name),(yyvsp[-1].var_name),1);
											}
#line 1609 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 200 "P1.y" /* yacc.c:1646  */
    { (yyval.var_name) = strcat((yyvsp[-2].var_name),","); (yyval.var_name) = strcat((yyval.var_name),(yyvsp[0].var_name));}
#line 1615 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 201 "P1.y" /* yacc.c:1646  */
    { (yyval.var_name) = (yyvsp[0].var_name);}
#line 1621 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 202 "P1.y" /* yacc.c:1646  */
    { char* temp= "";(yyval.var_name) = temp;}
#line 1627 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 205 "P1.y" /* yacc.c:1646  */
    {
	(yyval.var_name) = initString();sprintf((yyval.var_name),"class %s {\n\tpublic static void main ( String [] %s ) {\n\t\tSystem.out.println(%s);\n\t}\n}\n",(yyvsp[-18].var_name),(yyvsp[-9].var_name),(yyvsp[-4].var_name));	
}
#line 1635 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 209 "P1.y" /* yacc.c:1646  */
    { (yyval.var_name) = initString(); sprintf((yyval.var_name),"%s && %s",(yyvsp[-2].var_name),(yyvsp[0].var_name)); }
#line 1641 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 210 "P1.y" /* yacc.c:1646  */
    { (yyval.var_name) = initString(); sprintf((yyval.var_name),"%s || %s",(yyvsp[-2].var_name),(yyvsp[0].var_name)); }
#line 1647 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 211 "P1.y" /* yacc.c:1646  */
    { (yyval.var_name) = initString(); sprintf((yyval.var_name),"%s != %s",(yyvsp[-2].var_name),(yyvsp[0].var_name)); }
#line 1653 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 212 "P1.y" /* yacc.c:1646  */
    { (yyval.var_name) = initString(); sprintf((yyval.var_name),"%s <= %s",(yyvsp[-2].var_name),(yyvsp[0].var_name)); }
#line 1659 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 213 "P1.y" /* yacc.c:1646  */
    { (yyval.var_name) = initString(); sprintf((yyval.var_name),"%s + %s",(yyvsp[-2].var_name),(yyvsp[0].var_name)); }
#line 1665 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 214 "P1.y" /* yacc.c:1646  */
    { (yyval.var_name) = initString(); sprintf((yyval.var_name),"%s - %s",(yyvsp[-2].var_name),(yyvsp[0].var_name)); }
#line 1671 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 215 "P1.y" /* yacc.c:1646  */
    { (yyval.var_name) = initString(); sprintf((yyval.var_name),"%s * %s",(yyvsp[-2].var_name),(yyvsp[0].var_name)); }
#line 1677 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 216 "P1.y" /* yacc.c:1646  */
    { (yyval.var_name) = initString(); sprintf((yyval.var_name),"%s / %s",(yyvsp[-2].var_name),(yyvsp[0].var_name)); }
#line 1683 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 217 "P1.y" /* yacc.c:1646  */
    { (yyval.var_name) = initString(); sprintf((yyval.var_name),"%s [%s]",(yyvsp[-3].var_name),(yyvsp[-1].var_name)); }
#line 1689 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 218 "P1.y" /* yacc.c:1646  */
    { (yyval.var_name) = initString(); sprintf((yyval.var_name),"%s.length",(yyvsp[-2].var_name)); }
#line 1695 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 219 "P1.y" /* yacc.c:1646  */
    { (yyval.var_name) = (yyvsp[0].var_name); }
#line 1701 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 220 "P1.y" /* yacc.c:1646  */
    { (yyval.var_name) = initString(); sprintf((yyval.var_name),"%s.%s(%s)",(yyvsp[-5].var_name),(yyvsp[-3].var_name),(yyvsp[-1].var_name)); }
#line 1707 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 221 "P1.y" /* yacc.c:1646  */
    {(yyval.var_name) = REP((yyvsp[-3].var_name),(yyvsp[-1].var_name));}
#line 1713 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 224 "P1.y" /* yacc.c:1646  */
    { (yyval.var_name)= initString(); sprintf((yyval.var_name),"%s , %s",(yyvsp[-2].var_name),(yyvsp[0].var_name));}
#line 1719 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 225 "P1.y" /* yacc.c:1646  */
    { (yyval.var_name) =  (yyvsp[0].var_name);}
#line 1725 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 226 "P1.y" /* yacc.c:1646  */
    { (yyval.var_name) = "";}
#line 1731 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 229 "P1.y" /* yacc.c:1646  */
    { (yyval.var_name) = (yyvsp[0].var_name);}
#line 1737 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 230 "P1.y" /* yacc.c:1646  */
    { (yyval.var_name) = "true";}
#line 1743 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 231 "P1.y" /* yacc.c:1646  */
    { (yyval.var_name) = "false";}
#line 1749 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 232 "P1.y" /* yacc.c:1646  */
    { (yyval.var_name) = (yyvsp[0].var_name);}
#line 1755 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 233 "P1.y" /* yacc.c:1646  */
    {(yyval.var_name) = "this";}
#line 1761 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 234 "P1.y" /* yacc.c:1646  */
    { (yyval.var_name) = initString(); sprintf((yyval.var_name),"new int [%s]",(yyvsp[-1].var_name));}
#line 1767 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 235 "P1.y" /* yacc.c:1646  */
    { (yyval.var_name) = initString();sprintf((yyval.var_name),"new %s()",(yyvsp[-2].var_name));}
#line 1773 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 236 "P1.y" /* yacc.c:1646  */
    { (yyval.var_name) = initString();sprintf((yyval.var_name),"! %s",(yyvsp[0].var_name));}
#line 1779 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 237 "P1.y" /* yacc.c:1646  */
    { (yyval.var_name) = initString();sprintf((yyval.var_name),"( %s )",(yyvsp[-1].var_name));}
#line 1785 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 239 "P1.y" /* yacc.c:1646  */
    { (yyval.var_name) = "int []";}
#line 1791 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 240 "P1.y" /* yacc.c:1646  */
    { (yyval.var_name) = "boolean";}
#line 1797 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 241 "P1.y" /* yacc.c:1646  */
    { (yyval.var_name) = "int"; }
#line 1803 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 242 "P1.y" /* yacc.c:1646  */
    { (yyval.var_name) = (yyvsp[0].var_name);}
#line 1809 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 244 "P1.y" /* yacc.c:1646  */
    { (yyval.var_name) = initString(); sprintf((yyval.var_name),"%s %s %s;\n",(yyvsp[-3].var_name),(yyvsp[-2].var_name),(yyvsp[0].var_name));}
#line 1815 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 245 "P1.y" /* yacc.c:1646  */
    { (yyval.var_name) = "";}
#line 1821 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 247 "P1.y" /* yacc.c:1646  */
    { (yyval.var_name) = initString(); sprintf((yyval.var_name),"%s%s\n",(yyvsp[-1].var_name),(yyvsp[0].var_name));}
#line 1827 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 248 "P1.y" /* yacc.c:1646  */
    {(yyval.var_name) = "";}
#line 1833 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 250 "P1.y" /* yacc.c:1646  */
    { (yyval.var_name) = initString();sprintf((yyval.var_name),"class %s {\n%s %s \n}\n",(yyvsp[-4].var_name),(yyvsp[-2].var_name),(yyvsp[-1].var_name));}
#line 1839 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 251 "P1.y" /* yacc.c:1646  */
    {
								(yyval.var_name) = initString(); sprintf((yyval.var_name),"class %s extends %s {\n %s %s\n}\n",(yyvsp[-6].var_name),(yyvsp[-4].var_name),(yyvsp[-2].var_name),(yyvsp[-1].var_name));
								}
#line 1847 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 255 "P1.y" /* yacc.c:1646  */
    { (yyval.var_name) = initString(); sprintf((yyval.var_name),"public %s %s ( %s ) { \n %s %s \nreturn %s;\n}",(yyvsp[-11].var_name),(yyvsp[-10].var_name),(yyvsp[-8].var_name),(yyvsp[-5].var_name),(yyvsp[-4].var_name),(yyvsp[-2].var_name));}
#line 1853 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 257 "P1.y" /* yacc.c:1646  */
    { (yyval.var_name) = initString(); sprintf((yyval.var_name),"%s %s",(yyvsp[-1].var_name),(yyvsp[0].var_name));}
#line 1859 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 258 "P1.y" /* yacc.c:1646  */
    { (yyval.var_name) = initString(); sprintf((yyval.var_name),"%s %s, %s",(yyvsp[-3].var_name),(yyvsp[-2].var_name),(yyvsp[0].var_name));}
#line 1865 "P1.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 259 "P1.y" /* yacc.c:1646  */
    { (yyval.var_name) = "";}
#line 1871 "P1.tab.c" /* yacc.c:1646  */
    break;


#line 1875 "P1.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 262 "P1.y" /* yacc.c:1906  */


