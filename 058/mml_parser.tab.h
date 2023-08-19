/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_MML_PARSER_TAB_H_INCLUDED
# define YY_YY_MML_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    tIF = 258,                     /* tIF  */
    tBEGIN = 259,                  /* tBEGIN  */
    tEND = 260,                    /* tEND  */
    tFOREIGN = 261,                /* tFOREIGN  */
    tFORWARD = 262,                /* tFORWARD  */
    tPUBLIC = 263,                 /* tPUBLIC  */
    tAUTO = 264,                   /* tAUTO  */
    tPRIVATE = 265,                /* tPRIVATE  */
    tINPUT = 266,                  /* tINPUT  */
    tPRINT = 267,                  /* tPRINT  */
    tPRINTLN = 268,                /* tPRINTLN  */
    tWHILE = 269,                  /* tWHILE  */
    tSTOP = 270,                   /* tSTOP  */
    tNEXT = 271,                   /* tNEXT  */
    tRETURN = 272,                 /* tRETURN  */
    tSIZEOF = 273,                 /* tSIZEOF  */
    tTYPE_STRING = 274,            /* tTYPE_STRING  */
    tTYPE_INTEGER = 275,           /* tTYPE_INTEGER  */
    tTYPE_DOUBLE = 276,            /* tTYPE_DOUBLE  */
    tTYPE_VOID = 277,              /* tTYPE_VOID  */
    tARROW = 278,                  /* tARROW  */
    tINTEGER = 279,                /* tINTEGER  */
    tDOUBLE = 280,                 /* tDOUBLE  */
    tSTRING = 281,                 /* tSTRING  */
    tNULLPTR = 282,                /* tNULLPTR  */
    tIDENTIFIER = 283,             /* tIDENTIFIER  */
    tADDRESS = 284,                /* tADDRESS  */
    tOR = 285,                     /* tOR  */
    tAND = 286,                    /* tAND  */
    tNOT = 287,                    /* tNOT  */
    tEQ = 288,                     /* tEQ  */
    tNE = 289,                     /* tNE  */
    tLE = 290,                     /* tLE  */
    tGE = 291,                     /* tGE  */
    tUNARY = 292,                  /* tUNARY  */
    tIFX = 293,                    /* tIFX  */
    tELIF = 294,                   /* tELIF  */
    tELSE = 295                    /* tELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "mml_parser.y"

  //--- don't change *any* of these: if you do, you'll break the compiler.
  YYSTYPE() : type(cdk::primitive_type::create(0, cdk::TYPE_VOID)) {}
  ~YYSTYPE() {}
  YYSTYPE(const YYSTYPE &other) { *this = other; }
  YYSTYPE& operator=(const YYSTYPE &other) { type = other.type; return *this; }

  std::shared_ptr<cdk::basic_type> type;        /* expression type */
  //-- don't change *any* of these --- END!

  int                   i;	/* integer value */
  double                d;    /* double value */
  std::string          *s;	/* symbol name or string literal */
  cdk::basic_node      *node;	/* node pointer */
  cdk::sequence_node   *sequence;
  cdk::expression_node *expression; /* expression nodes */
  cdk::lvalue_node     *lvalue;

  mml::block_node                *block;
  mml::variable_declaration_node *vardec;

  std::vector<std::shared_ptr<cdk::basic_type>> *type_vec;

#line 128 "mml_parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (std::shared_ptr<cdk::compiler> compiler);


#endif /* !YY_YY_MML_PARSER_TAB_H_INCLUDED  */
