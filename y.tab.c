
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "parser.y"

#include"AST.h"
#include<string>
#include<iostream>
#include<vector>
AST::Program * Root;
extern int yylex(void);
void yyerror(char *s){
    std::printf("Error: %s\n", s);
    std::exit(1); 
}


/* Line 189 of yacc.c  */
#line 87 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IF = 258,
     ELSE = 259,
     DO = 260,
     WHILE = 261,
     SWITCH = 262,
     CASE = 263,
     DEFAULT = 264,
     BREAK = 265,
     CONTINUE = 266,
     RETURN = 267,
     LPAREN = 268,
     RPAREN = 269,
     LBRACE = 270,
     RBRACE = 271,
     ASSIGN = 272,
     LBRACKET = 273,
     RBRACKET = 274,
     FOR = 275,
     MUL = 276,
     DIV = 277,
     PLUS = 278,
     SUB = 279,
     AND = 280,
     OR = 281,
     MOD = 282,
     SAND = 283,
     NOT = 284,
     EQU = 285,
     GE = 286,
     LE = 287,
     GT = 288,
     LT = 289,
     NE = 290,
     SEMI = 291,
     COLON = 292,
     COMMA = 293,
     INT = 294,
     BOOL = 295,
     CHAR = 296,
     FLOAT = 297,
     DOUBLE = 298,
     SHORT = 299,
     LONG = 300,
     VOID = 301,
     INTERGER = 302,
     REAL = 303,
     STRING = 304,
     Identifier = 305,
     CHARACTER = 306
   };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define DO 260
#define WHILE 261
#define SWITCH 262
#define CASE 263
#define DEFAULT 264
#define BREAK 265
#define CONTINUE 266
#define RETURN 267
#define LPAREN 268
#define RPAREN 269
#define LBRACE 270
#define RBRACE 271
#define ASSIGN 272
#define LBRACKET 273
#define RBRACKET 274
#define FOR 275
#define MUL 276
#define DIV 277
#define PLUS 278
#define SUB 279
#define AND 280
#define OR 281
#define MOD 282
#define SAND 283
#define NOT 284
#define EQU 285
#define GE 286
#define LE 287
#define GT 288
#define LT 289
#define NE 290
#define SEMI 291
#define COLON 292
#define COMMA 293
#define INT 294
#define BOOL 295
#define CHAR 296
#define FLOAT 297
#define DOUBLE 298
#define SHORT 299
#define LONG 300
#define VOID 301
#define INTERGER 302
#define REAL 303
#define STRING 304
#define Identifier 305
#define CHARACTER 306




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 13 "parser.y"

    int inum;
    double dnum;
    char cval;
    string * str;
    AST::Program * program;
     AST::Stmt * stmt;
     AST::Decl * decl;
     AST::Fundecl * fundecl;
    AST::Block * block;
    AST::Arg * arg;
    AST::Vardecl * vardecl;
     AST::Vartype * vartype;
    AST::Var * var;
    AST::ConditionStmt * conditionStmt;
     AST::LoopStmt * loopStmt;
    AST:: WhileStmt * whileStmt;
    AST::DoStmt * doStmt;
    AST::ForStmt * forStmt;
    AST::SwitchStmt * switchStmt;
    AST::Case * casel;
    AST::ReturnStmt * returnStmt;
    AST::BreakStmt *  breakStmt;
    AST::ContinueStmt* continueStmt;
    AST::Expression * expression;
    AST::Id * id;
    AST::Value * value;
    AST::Var_id * var_id;
    AST::Var_array * var_array;
    AST::ArgList *argList;
    AST::VarList *varList;
    AST::ExpressionList * expressionList;
    AST:: CaseList * caseList;
    AST:: ValueList * valueList;
    AST::Stmts* stmts;



/* Line 214 of yacc.c  */
#line 264 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 276 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   502

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  90
/* YYNRULES -- Number of states.  */
#define YYNSTATES  169

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    11,    13,    15,    18,
      20,    22,    24,    26,    28,    30,    32,    39,    46,    50,
      54,    56,    57,    60,    62,    66,    68,    70,    72,    74,
      76,    78,    80,    84,    86,    88,    90,    92,    96,   101,
     110,   114,   116,   117,   119,   120,   122,   124,   129,   133,
     137,   141,   145,   149,   153,   157,   161,   165,   169,   173,
     177,   181,   185,   189,   192,   195,   197,   199,   201,   203,
     205,   209,   211,   212,   218,   226,   228,   230,   232,   238,
     246,   256,   265,   273,   276,   277,   282,   286,   289,   292,
     296
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      53,     0,    -1,    54,    -1,    54,    55,    -1,    -1,    56,
      -1,    73,    -1,    74,    -1,    68,    36,    -1,    58,    -1,
      78,    -1,    81,    -1,    82,    -1,    83,    -1,    57,    -1,
      61,    -1,    62,    70,    13,    59,    14,    36,    -1,    62,
      70,    13,    59,    14,    58,    -1,    15,    54,    16,    -1,
      59,    38,    60,    -1,    60,    -1,    -1,    62,    70,    -1,
      62,    -1,    62,    63,    36,    -1,    39,    -1,    41,    -1,
      42,    -1,    43,    -1,    44,    -1,    45,    -1,    46,    -1,
      63,    38,    64,    -1,    64,    -1,    65,    -1,    66,    -1,
      70,    -1,    70,    17,    69,    -1,    70,    18,    69,    19,
      -1,    70,    18,    69,    19,    17,    15,    67,    16,    -1,
      67,    38,    71,    -1,    71,    -1,    -1,    69,    -1,    -1,
      70,    -1,    71,    -1,    70,    13,    72,    14,    -1,    13,
      69,    14,    -1,    69,    27,    69,    -1,    69,    21,    69,
      -1,    69,    22,    69,    -1,    69,    23,    69,    -1,    69,
      24,    69,    -1,    69,    25,    69,    -1,    69,    26,    69,
      -1,    69,    30,    69,    -1,    69,    31,    69,    -1,    69,
      32,    69,    -1,    69,    33,    69,    -1,    69,    34,    69,
      -1,    69,    35,    69,    -1,    69,    17,    69,    -1,    28,
      69,    -1,    29,    69,    -1,    50,    -1,    47,    -1,    48,
      -1,    51,    -1,    49,    -1,    72,    38,    69,    -1,    69,
      -1,    -1,     3,    13,    69,    14,    55,    -1,     3,    13,
      69,    14,    55,     4,    55,    -1,    77,    -1,    75,    -1,
      76,    -1,     6,    13,    69,    14,    55,    -1,     5,    55,
       6,    13,    69,    14,    36,    -1,    20,    13,    68,    36,
      69,    36,    68,    14,    55,    -1,    20,    13,    61,    69,
      36,    68,    14,    55,    -1,     7,    13,    68,    14,    15,
      79,    16,    -1,    79,    80,    -1,    -1,     8,    68,    37,
      54,    -1,     9,    37,    54,    -1,    11,    36,    -1,    10,
      36,    -1,    12,    69,    36,    -1,    12,    36,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   112,   112,   115,   116,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   130,   131,   134,   135,   138,   141,
     142,   143,   146,   147,   150,   153,   154,   155,   156,   157,
     158,   159,   170,   171,   174,   175,   178,   179,   182,   183,
     186,   187,   188,   190,   191,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   216,   220,   221,   222,   223,
     226,   227,   228,   232,   233,   236,   237,   238,   241,   244,
     247,   248,   251,   254,   255,   258,   259,   262,   265,   268,
     269
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "DO", "WHILE", "SWITCH",
  "CASE", "DEFAULT", "BREAK", "CONTINUE", "RETURN", "LPAREN", "RPAREN",
  "LBRACE", "RBRACE", "ASSIGN", "LBRACKET", "RBRACKET", "FOR", "MUL",
  "DIV", "PLUS", "SUB", "AND", "OR", "MOD", "SAND", "NOT", "EQU", "GE",
  "LE", "GT", "LT", "NE", "SEMI", "COLON", "COMMA", "INT", "BOOL", "CHAR",
  "FLOAT", "DOUBLE", "SHORT", "LONG", "VOID", "INTERGER", "REAL", "STRING",
  "Identifier", "CHARACTER", "$accept", "Program", "Stmts", "Stmt", "Decl",
  "Fundecl", "Block", "FunArg_list", "Arg", "Vardecl", "Vartype",
  "Varlist", "Var", "Var_id", "Var_array", "Init", "Exp", "Expression",
  "ID", "VALUE", "Call_arglist", "ConditionStmt", "LoopStmt", "WhileStmt",
  "DoStmt", "ForStmt", "SwitchStmt", "CaseStmt", "Case", "ContinueStmt",
  "BreakStmt", "ReturnStmt", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    54,    54,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    56,    56,    57,    57,    58,    59,
      59,    59,    60,    60,    61,    62,    62,    62,    62,    62,
      62,    62,    63,    63,    64,    64,    65,    65,    66,    66,
      67,    67,    67,    68,    68,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    70,    71,    71,    71,    71,
      72,    72,    72,    73,    73,    74,    74,    74,    75,    76,
      77,    77,    78,    79,    79,    80,    80,    81,    82,    83,
      83
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     6,     6,     3,     3,
       1,     0,     2,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     3,     4,     8,
       3,     1,     0,     1,     0,     1,     1,     4,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     1,     1,     1,     1,     1,
       3,     1,     0,     5,     7,     1,     1,     1,     5,     7,
       9,     8,     7,     2,     0,     4,     3,     2,     2,     3,
       2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,     0,    44,     0,     0,     0,     0,
       0,     0,     4,     0,     0,     0,    25,    26,    27,    28,
      29,    30,    31,    66,    67,    69,    65,    68,     3,     5,
      14,     9,    15,     0,     0,    43,    45,    46,     6,     7,
      76,    77,    75,    10,    11,    12,    13,     0,     0,     0,
      44,    88,    87,    90,     0,     0,    44,    44,    63,    64,
       0,    33,    34,    35,    36,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      72,     0,     0,     0,     0,    89,    48,    18,     0,     0,
       0,    24,     0,    21,     0,     0,    62,    50,    51,    52,
      53,    54,    55,    49,    56,    57,    58,    59,    60,    61,
      71,     0,    44,     0,    44,     0,     0,    36,     0,    32,
       0,    20,    23,    37,     0,    47,     0,    73,     0,    78,
      84,    44,     0,     0,     0,    22,    38,    70,    44,     0,
       0,     0,    44,    16,    17,    19,     0,    74,    79,    44,
       0,    82,    83,    44,     0,    42,     0,     4,    81,    44,
       0,    41,     4,    86,    80,    39,     0,    85,    40
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    28,    29,    30,    31,   120,   121,    32,
      33,    60,    61,    62,    63,   160,    34,    35,    36,    37,
     111,    38,    39,    40,    41,    42,    43,   140,   152,    44,
      45,    46
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -146
static const yytype_int16 yypact[] =
{
    -146,     8,   114,  -146,     7,   212,    20,    22,     6,    21,
      -4,     2,  -146,    25,     2,     2,  -146,  -146,  -146,  -146,
    -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,
    -146,  -146,  -146,    27,    39,   438,    43,  -146,  -146,  -146,
    -146,  -146,  -146,  -146,  -146,  -146,  -146,     2,    75,     2,
       2,  -146,  -146,  -146,   359,   274,   163,   236,  -146,  -146,
     -20,  -146,  -146,  -146,    61,  -146,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   296,    69,   318,    70,  -146,  -146,  -146,     2,    27,
      47,  -146,    27,    49,     2,     2,   438,  -146,  -146,     1,
       1,   166,   453,  -146,   468,    77,    77,    77,    77,   468,
     438,    -9,   212,     2,   212,    82,   379,    37,     2,  -146,
      -1,  -146,    27,   438,   419,  -146,     2,    98,   340,  -146,
    -146,     2,   399,     4,    49,  -146,    91,   438,   212,    78,
      18,   102,     2,  -146,  -146,  -146,   107,  -146,  -146,     2,
      86,  -146,  -146,   212,   116,    64,    94,  -146,  -146,   212,
      -2,  -146,  -146,   114,  -146,  -146,    64,   114,  -146
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -146,  -146,   -11,    -5,  -146,  -146,     3,  -146,    -6,    80,
     -45,  -146,    40,  -146,  -146,  -146,   -46,    -8,   -16,  -145,
    -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,
    -146,  -146
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -45
static const yytype_int16 yytable[] =
{
      48,    56,    54,    55,    84,   125,    58,    59,     3,    11,
     161,    90,    89,   133,   165,    11,    91,    64,    92,    12,
      47,   168,    67,    68,    14,    15,   149,   150,    73,   126,
      14,    15,    53,    49,   151,    50,   166,   134,    57,    81,
     143,    83,    51,    23,    24,    25,    26,    27,   122,    23,
      24,    25,    26,    27,    94,    95,    80,    52,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   117,    93,    65,   117,    26,    94,    95,
     116,    82,   113,   118,   115,   141,   123,   124,    16,   122,
      17,    18,    19,    20,    21,    22,   154,   130,    67,    68,
      69,    70,   138,   156,    73,   128,   135,   127,   146,   129,
     132,    23,    24,    25,   148,    27,   153,     4,   137,     5,
       6,     7,   155,   157,     8,     9,    10,    11,   145,    12,
     159,   162,   119,   147,    13,     0,   144,    88,     0,     0,
       0,     0,    14,    15,     0,     0,   163,     0,   158,     0,
     -44,   167,     0,    16,   164,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,     4,     0,     5,     6,
       7,     0,     0,     8,     9,    10,    11,     0,    12,    87,
       0,     0,     0,    13,     0,     0,     0,    67,    68,    69,
      70,    14,    15,    73,     0,     0,    74,    75,    76,    77,
      78,    79,    16,     0,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,     4,     0,     5,     6,     7,
       0,     0,     8,     9,    10,    11,     0,    12,     0,     0,
       0,     0,    13,     0,     0,     0,     0,     0,     0,     0,
      14,    15,     0,     0,     0,     0,     0,     0,     0,    11,
       0,    16,     0,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    14,    15,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    16,     0,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    86,     0,
       0,    66,     0,     0,     0,    67,    68,    69,    70,    71,
      72,    73,     0,     0,    74,    75,    76,    77,    78,    79,
     112,     0,     0,    66,     0,     0,     0,    67,    68,    69,
      70,    71,    72,    73,     0,     0,    74,    75,    76,    77,
      78,    79,   114,     0,     0,    66,     0,     0,     0,    67,
      68,    69,    70,    71,    72,    73,     0,     0,    74,    75,
      76,    77,    78,    79,   139,     0,     0,    66,     0,     0,
       0,    67,    68,    69,    70,    71,    72,    73,     0,     0,
      74,    75,    76,    77,    78,    79,    66,     0,     0,     0,
      67,    68,    69,    70,    71,    72,    73,     0,     0,    74,
      75,    76,    77,    78,    79,    85,    66,     0,     0,     0,
      67,    68,    69,    70,    71,    72,    73,     0,     0,    74,
      75,    76,    77,    78,    79,   131,    66,     0,     0,     0,
      67,    68,    69,    70,    71,    72,    73,     0,     0,    74,
      75,    76,    77,    78,    79,   142,    66,     0,   136,     0,
      67,    68,    69,    70,    71,    72,    73,     0,     0,    74,
      75,    76,    77,    78,    79,    66,     0,     0,     0,    67,
      68,    69,    70,    71,    72,    73,     0,     0,    74,    75,
      76,    77,    78,    79,    67,    68,    69,    70,    71,     0,
      73,     0,     0,    74,    75,    76,    77,    78,    79,    67,
      68,    69,    70,     0,     0,    73,     0,     0,     0,    75,
      76,    77,    78
};

static const yytype_int16 yycheck[] =
{
       5,    12,    10,    11,    50,    14,    14,    15,     0,    13,
     155,    57,    57,    14,    16,    13,    36,    33,    38,    15,
      13,   166,    21,    22,    28,    29,     8,     9,    27,    38,
      28,    29,    36,    13,    16,    13,    38,    38,    13,    47,
      36,    49,    36,    47,    48,    49,    50,    51,    93,    47,
      48,    49,    50,    51,    17,    18,    13,    36,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    89,    13,    36,    92,    50,    17,    18,
      88,     6,    13,    36,    14,   131,    94,    95,    39,   134,
      41,    42,    43,    44,    45,    46,   142,    15,    21,    22,
      23,    24,     4,   149,    27,   113,   122,   112,    17,   114,
     118,    47,    48,    49,    36,    51,    14,     3,   126,     5,
       6,     7,    15,    37,    10,    11,    12,    13,   134,    15,
      14,    37,    92,   138,    20,    -1,   133,    57,    -1,    -1,
      -1,    -1,    28,    29,    -1,    -1,   157,    -1,   153,    -1,
      36,   162,    -1,    39,   159,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,     3,    -1,     5,     6,
       7,    -1,    -1,    10,    11,    12,    13,    -1,    15,    16,
      -1,    -1,    -1,    20,    -1,    -1,    -1,    21,    22,    23,
      24,    28,    29,    27,    -1,    -1,    30,    31,    32,    33,
      34,    35,    39,    -1,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,     3,    -1,     5,     6,     7,
      -1,    -1,    10,    11,    12,    13,    -1,    15,    -1,    -1,
      -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,
      -1,    39,    -1,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    28,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    -1,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    14,    -1,
      -1,    17,    -1,    -1,    -1,    21,    22,    23,    24,    25,
      26,    27,    -1,    -1,    30,    31,    32,    33,    34,    35,
      14,    -1,    -1,    17,    -1,    -1,    -1,    21,    22,    23,
      24,    25,    26,    27,    -1,    -1,    30,    31,    32,    33,
      34,    35,    14,    -1,    -1,    17,    -1,    -1,    -1,    21,
      22,    23,    24,    25,    26,    27,    -1,    -1,    30,    31,
      32,    33,    34,    35,    14,    -1,    -1,    17,    -1,    -1,
      -1,    21,    22,    23,    24,    25,    26,    27,    -1,    -1,
      30,    31,    32,    33,    34,    35,    17,    -1,    -1,    -1,
      21,    22,    23,    24,    25,    26,    27,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    17,    -1,    -1,    -1,
      21,    22,    23,    24,    25,    26,    27,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    17,    -1,    -1,    -1,
      21,    22,    23,    24,    25,    26,    27,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    17,    -1,    19,    -1,
      21,    22,    23,    24,    25,    26,    27,    -1,    -1,    30,
      31,    32,    33,    34,    35,    17,    -1,    -1,    -1,    21,
      22,    23,    24,    25,    26,    27,    -1,    -1,    30,    31,
      32,    33,    34,    35,    21,    22,    23,    24,    25,    -1,
      27,    -1,    -1,    30,    31,    32,    33,    34,    35,    21,
      22,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,    31,
      32,    33,    34
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    53,    54,     0,     3,     5,     6,     7,    10,    11,
      12,    13,    15,    20,    28,    29,    39,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    55,    56,
      57,    58,    61,    62,    68,    69,    70,    71,    73,    74,
      75,    76,    77,    78,    81,    82,    83,    13,    55,    13,
      13,    36,    36,    36,    69,    69,    54,    13,    69,    69,
      63,    64,    65,    66,    70,    36,    17,    21,    22,    23,
      24,    25,    26,    27,    30,    31,    32,    33,    34,    35,
      13,    69,     6,    69,    68,    36,    14,    16,    61,    62,
      68,    36,    38,    13,    17,    18,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    72,    14,    13,    14,    14,    69,    70,    36,    64,
      59,    60,    62,    69,    69,    14,    38,    55,    69,    55,
      15,    36,    69,    14,    38,    70,    19,    69,     4,    14,
      79,    68,    36,    36,    58,    60,    17,    55,    36,     8,
       9,    16,    80,    14,    68,    15,    68,    37,    55,    14,
      67,    71,    37,    54,    55,    16,    38,    54,    71
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1455 of yacc.c  */
#line 112 "parser.y"
    {(yyval.program) = new AST::Program((yyvsp[(1) - (1)].stmts)); Root = (yyval.program);  }
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 115 "parser.y"
    {(yyval.stmts)=(yyvsp[(1) - (2)].stmts); (yyval.stmts)->push_back((yyvsp[(2) - (2)].stmt));}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 116 "parser.y"
    {(yyval.stmts)=new AST::Stmts(); }
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 119 "parser.y"
    {(yyval.stmt)=(yyvsp[(1) - (1)].decl);}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 120 "parser.y"
    {(yyval.stmt)=(yyvsp[(1) - (1)].conditionStmt);}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 121 "parser.y"
    {(yyval.stmt)=(yyvsp[(1) - (1)].loopStmt);}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 122 "parser.y"
    {(yyval.stmt)=(yyvsp[(1) - (2)].expression);}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 123 "parser.y"
    {(yyval.stmt)=(yyvsp[(1) - (1)].block);}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 124 "parser.y"
    {(yyval.stmt)=(yyvsp[(1) - (1)].switchStmt);}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 125 "parser.y"
    {(yyval.stmt)=(yyvsp[(1) - (1)].continueStmt);}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 126 "parser.y"
    {(yyval.stmt)=(yyvsp[(1) - (1)].breakStmt);}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 127 "parser.y"
    {(yyval.stmt)=(yyvsp[(1) - (1)].returnStmt);}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 130 "parser.y"
    {(yyval.decl)=(yyvsp[(1) - (1)].fundecl);}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 131 "parser.y"
    {(yyval.decl)=(yyvsp[(1) - (1)].vardecl);}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 134 "parser.y"
    {(yyval.fundecl) = new AST::Fundecl ((yyvsp[(1) - (6)].vartype),(yyvsp[(2) - (6)].id),(yyvsp[(4) - (6)].argList)); }
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 135 "parser.y"
    {(yyval.fundecl) = new AST::Fundecl ((yyvsp[(1) - (6)].vartype),(yyvsp[(2) - (6)].id),(yyvsp[(4) - (6)].argList), (yyvsp[(6) - (6)].block)); }
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 138 "parser.y"
    {(yyval.block)= new AST::Block((yyvsp[(2) - (3)].stmts));}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 141 "parser.y"
    {(yyval.argList)=(yyvsp[(1) - (3)].argList); (yyval.argList)->push_back((yyvsp[(3) - (3)].arg));}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 142 "parser.y"
    {(yyval.argList)=new AST::ArgList(); (yyval.argList)->push_back((yyvsp[(1) - (1)].arg));}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 143 "parser.y"
    {(yyval.argList)=NULL;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 146 "parser.y"
    {(yyval.arg)= new AST::Arg((yyvsp[(1) - (2)].vartype),(yyvsp[(2) - (2)].id));}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 147 "parser.y"
    {(yyval.arg)= new AST::Arg((yyvsp[(1) - (1)].vartype));}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 150 "parser.y"
    {(yyval.vardecl) = new AST::Vardecl ((yyvsp[(1) - (3)].vartype),(yyvsp[(2) - (3)].varList));}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 153 "parser.y"
    {(yyval.vartype) = new AST::Vartype(_Int);}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 154 "parser.y"
    {(yyval.vartype) = new AST::Vartype(_Char);}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 155 "parser.y"
    {(yyval.vartype) = new AST::Vartype(_Float);}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 156 "parser.y"
    {(yyval.vartype) = new AST::Vartype(_Double);}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 157 "parser.y"
    {(yyval.vartype) = new AST::Vartype(_Short);}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 158 "parser.y"
    {(yyval.vartype) = new AST::Vartype(_Long);}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 159 "parser.y"
    {(yyval.vartype) = new AST::Vartype(_Void);}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 170 "parser.y"
    {(yyval.varList) = (yyvsp[(1) - (3)].varList) ; (yyval.varList)->push_back((yyvsp[(3) - (3)].var));}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 171 "parser.y"
    {(yyval.varList) = new AST::VarList(); (yyval.varList)->push_back((yyvsp[(1) - (1)].var));}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 174 "parser.y"
    {(yyval.var)=(yyvsp[(1) - (1)].var_id);}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 175 "parser.y"
    {(yyval.var)=(yyvsp[(1) - (1)].var_array);}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 178 "parser.y"
    {(yyval.var_id) = new AST::Var_id((yyvsp[(1) - (1)].id));}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 179 "parser.y"
    {(yyval.var_id) = new AST::Var_id((yyvsp[(1) - (3)].id),(yyvsp[(3) - (3)].expression));}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 182 "parser.y"
    {(yyval.var_array) = new AST::Var_array((yyvsp[(1) - (4)].id),(yyvsp[(3) - (4)].expression));}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 183 "parser.y"
    {(yyval.var_array) = new AST::Var_array((yyvsp[(1) - (8)].id),(yyvsp[(3) - (8)].expression),(yyvsp[(7) - (8)].valueList));}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 186 "parser.y"
    {(yyval.valueList) = (yyvsp[(1) - (3)].valueList) ; (yyval.valueList)->push_back((yyvsp[(3) - (3)].value));}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 187 "parser.y"
    {(yyval.valueList) = new AST::ValueList(); (yyval.valueList)->push_back((yyvsp[(1) - (1)].value));}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 188 "parser.y"
    {(yyval.valueList) = NULL;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 190 "parser.y"
    {(yyval.expression)=(yyvsp[(1) - (1)].expression);}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 191 "parser.y"
    {(yyval.expression)=NULL;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 194 "parser.y"
    {(yyval.expression)= (yyvsp[(1) - (1)].id);}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 195 "parser.y"
    {(yyval.expression)= (yyvsp[(1) - (1)].value);}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 196 "parser.y"
    {(yyval.expression) = new AST::Func_call((yyvsp[(1) - (4)].id),(yyvsp[(3) - (4)].expressionList));}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 197 "parser.y"
    {(yyval.expression)=(yyvsp[(2) - (3)].expression);}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 198 "parser.y"
    {(yyval.expression)=new AST::Mod((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression)) ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 199 "parser.y"
    {(yyval.expression)=new AST::Mul((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression)) ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 200 "parser.y"
    {(yyval.expression)=new AST::Div((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression)) ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 201 "parser.y"
    {(yyval.expression)=new AST::Plus((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression)) ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 202 "parser.y"
    {(yyval.expression)=new AST::Sub((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression)) ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 203 "parser.y"
    {(yyval.expression)=new AST::And((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression)) ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 204 "parser.y"
    {(yyval.expression)=new AST::Or((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression)) ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 205 "parser.y"
    {(yyval.expression)=new AST::Equ((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression)) ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 206 "parser.y"
    {(yyval.expression)=new AST::Ge((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression)) ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 207 "parser.y"
    {(yyval.expression)=new AST::Le((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression)) ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 208 "parser.y"
    {(yyval.expression)=new AST::Gt((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression)) ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 209 "parser.y"
    {(yyval.expression)=new AST::Lt((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression)) ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 210 "parser.y"
    {(yyval.expression)=new AST::Ne((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression)) ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 211 "parser.y"
    {(yyval.expression)=new AST::Assign((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression)) ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 212 "parser.y"
    {(yyval.expression)=new AST::Getaddess((yyvsp[(2) - (2)].expression));}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 213 "parser.y"
    {(yyval.expression)=new AST::Not((yyvsp[(2) - (2)].expression));}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 216 "parser.y"
    {(yyval.id)= new AST::Id((yyvsp[(1) - (1)].str));}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 220 "parser.y"
    {(yyval.value) = new AST::IntNode((yyvsp[(1) - (1)].inum));}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 221 "parser.y"
    {(yyval.value) = new AST::DoubleNode((yyvsp[(1) - (1)].dnum));}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 222 "parser.y"
    {(yyval.value) = new AST::CharNode((yyvsp[(1) - (1)].cval));}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 223 "parser.y"
    {(yyval.value) = new AST::StrNode((yyvsp[(1) - (1)].str));}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 226 "parser.y"
    {(yyval.expressionList)=(yyvsp[(1) - (3)].expressionList); (yyval.expressionList)->push_back((yyvsp[(3) - (3)].expression));}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 227 "parser.y"
    {(yyval.expressionList)= new AST::ExpressionList(); (yyval.expressionList)->push_back ((yyvsp[(1) - (1)].expression));}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 228 "parser.y"
    {(yyval.expressionList)= NULL;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 232 "parser.y"
    {(yyval.conditionStmt) = new AST::ConditionStmt((yyvsp[(3) - (5)].expression),(yyvsp[(5) - (5)].stmt));}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 233 "parser.y"
    {(yyval.conditionStmt) = new AST::ConditionStmt((yyvsp[(3) - (7)].expression),(yyvsp[(5) - (7)].stmt),(yyvsp[(7) - (7)].stmt));}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 236 "parser.y"
    {(yyval.loopStmt)=(yyvsp[(1) - (1)].forStmt);}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 237 "parser.y"
    {(yyval.loopStmt)=(yyvsp[(1) - (1)].whileStmt);}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 238 "parser.y"
    {(yyval.loopStmt)=(yyvsp[(1) - (1)].doStmt);}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 241 "parser.y"
    {(yyval.whileStmt) = new AST::WhileStmt((yyvsp[(3) - (5)].expression),(yyvsp[(5) - (5)].stmt));}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 244 "parser.y"
    {(yyval.doStmt) = new AST::DoStmt((yyvsp[(5) - (7)].expression),(yyvsp[(2) - (7)].stmt));}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 247 "parser.y"
    {(yyval.forStmt) = new AST::ForStmt((yyvsp[(3) - (9)].expression),(yyvsp[(5) - (9)].expression),(yyvsp[(7) - (9)].expression),(yyvsp[(9) - (9)].stmt));}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 248 "parser.y"
    {(yyval.forStmt) = new AST::ForStmt((yyvsp[(3) - (8)].vardecl),(yyvsp[(4) - (8)].expression),(yyvsp[(6) - (8)].expression),(yyvsp[(8) - (8)].stmt));}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 251 "parser.y"
    {(yyval.switchStmt) = new AST::SwitchStmt((yyvsp[(3) - (7)].expression),*(yyvsp[(6) - (7)].caseList));}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 254 "parser.y"
    {(yyval.caseList)=(yyvsp[(1) - (2)].caseList); (yyval.caseList)->push_back((yyvsp[(2) - (2)].casel));}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 255 "parser.y"
    {(yyval.caseList) = new AST::CaseList();}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 258 "parser.y"
    {(yyval.casel)= new AST::Case((yyvsp[(2) - (4)].expression),(yyvsp[(4) - (4)].stmts));}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 259 "parser.y"
    {(yyval.casel) = new AST::Case(NULL,(yyvsp[(3) - (3)].stmts));}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 262 "parser.y"
    {(yyval.continueStmt) = new AST::ContinueStmt();}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 265 "parser.y"
    {(yyval.breakStmt) = new AST::BreakStmt();}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 268 "parser.y"
    {(yyval.returnStmt) = new AST::ReturnStmt((yyvsp[(2) - (3)].expression));}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 269 "parser.y"
    {(yyval.returnStmt) = new AST::ReturnStmt(); }
    break;



/* Line 1455 of yacc.c  */
#line 2315 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 271 "parser.y"



int yywrap(){
    return 1;
}
int main()
{
    yyparse();
}

