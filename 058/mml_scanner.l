%option c++ prefix="mml_scanner_" outfile="mml_scanner.cpp"
%option stack noyywrap yylineno 8bit debug
%{ 
// make relevant includes before including the parser's tab file
#include <string>
#include <algorithm>
#include <cstring>
#include <cdk/ast/sequence_node.h>
#include <cdk/ast/expression_node.h>
#include <cdk/ast/lvalue_node.h>
#include "mml_parser.tab.h"

// don't change this
#define yyerror LexerError

%}

LETTER      [A-Za-z]
IDENTIFIER   {LETTER}({LETTER}|[[:digit:]])*

DIGIT [0-9]
NONZERO [1-9]
OCTAL [0-7]


%x X_COMMENT
%x X_STRING X_STRIGN
%x X_OCTA
%%
  /*yydebug=1; set_debug(1);*/

  /* ====================================================================== */
  /* ====[                      3.2 - Comments                        ]==== */ 
  /* ====================================================================== */

"//".*$               ; /*ignore comments*/

"/*"                   yy_push_state(X_COMMENT);
<X_COMMENT>"/*"        yy_push_state(X_COMMENT);
<X_COMMENT>"*/"        yy_pop_state();
<X_COMMENT>.|"\n"      ;  /* ignore inside of comments */

  /* ====================================================================== */
  /* ====[                      1.1 - Tipos de Dados                  ]==== */
  /* ====================================================================== */

"int"       return tTYPE_INTEGER;
"double"    return tTYPE_DOUBLE;
"string"    return tTYPE_STRING;
[<>]        return *yytext;
"void"      return tTYPE_VOID;

 
  /* ====================================================================== */
  /* ====[                      3.3 - Palavras Chave                  ]==== */
  /* ====================================================================== */

"foreign"   return tFOREIGN;               
"forward"   return tFORWARD;
"public"    return tPUBLIC;
"auto"      return tAUTO;


"if"        return tIF;
"elif"      return tELIF;
"else"      return tELSE; 
"while"     return tWHILE; 
"stop"      return tSTOP;
"next"      return tNEXT;
"return"    return tRETURN;

"input"     return tINPUT;
"null"      return tNULLPTR;
"sizeof"    return tSIZEOF;

"begin"     return tBEGIN; 
"end"       return tEND;

"?"         return tADDRESS;


 /* ====================================================================== */
 /* ====[                      5 - Funções                           ]==== */
 /* ====================================================================== */

"@"  return *yytext;

 /* ====================================================================== */
 /* ====[              3.6 - Delimitadores e Terminadores            ]==== */
 /* ====[                    Operadores de Impressão                 ]==== */
 /* ====[              5.3 Corpo de Função                           ]==== */
 /* ====================================================================== */

"!"       return tPRINT;
"!!"      return tPRINTLN;

 /* ====================================================================== */
 /* ====[              3.8.1 - inteiros                              ]==== */
 /* ====================================================================== */

{NONZERO}{DIGIT}* {
  errno = 0;
  long long int val = strtoll(yytext, NULL, 10);
  if (errno == ERANGE) {
    yyerror("Integer overflow");
  }
  yylval.i = val;
  return tINTEGER;
}
[0] {
  yylval.i = 0;
  return tINTEGER;
}

[0]{OCTAL}+ {
  errno = 0;
  long long int val = strtoll(yytext, NULL, 8);
  if (errno == ERANGE) {
    yyerror("Integer overflow");
  }
  yylval.i = val;
  return tINTEGER;
}


 /* ====================================================================== */
 /* ====[              3.8.1 - reais                                 ]==== */
 /* ====================================================================== */


[0-9]*\.[0-9]+([Ee][-+]?[0-9]+)?    {
  errno = 0;
  long double val = strtold(yytext, NULL);
  if (errno == ERANGE) {
    yyerror("Double overflow");
  }
  yylval.d = val;
  return tDOUBLE;
}

[0-9]+\.[0-9]*([Ee][-+]?[0-9]+)? {
  errno = 0;
  long double val = strtold(yytext, NULL);
  if (errno == ERANGE) {
    yyerror("Double overflow");
  }
  yylval.d = val;
  return tDOUBLE;
}

[0-9]+([Ee][-+]?[0-9]+) {
  errno = 0;
  long double val = strtold(yytext, NULL);
  if (errno == ERANGE) {
    yyerror("Double overflow");
  }
  yylval.d = val;
  return tDOUBLE;
}


 /* ====================================================================== */
 /* ====[              3.8.3 - cadeia de caracteres                  ]==== */
 /* ====================================================================== */

\"                           yy_push_state(X_STRING); yylval.s = new std::string("");
<X_STRING>\"                 yy_pop_state(); return tSTRING;
<X_STRING>\\\"               *yylval.s += yytext + 1;
<X_STRING>\\\\               *yylval.s += yytext + 1;
<X_STRING>\\t                *yylval.s += '\t';
<X_STRING>\\n                *yylval.s += '\n';
<X_STRING>\\r                *yylval.s += '\r';
<X_STRING>\\0                yy_push_state(X_OCTA);
<X_STRING>\\[0-7]{1,3}       *yylval.s += (char) strtoul(yytext+1, NULL, 8);
<X_STRING>\0                 yyerror("nullbyte in string");
<X_STRING>.|\n               *yylval.s += yytext;
<X_STRIGN>\0                 yyerror("null byte in string");

<X_OCTA>\0             { yyerror("Null byte in string"); }
<X_OCTA>\"             { yy_pop_state(); return tSTRING; }
<X_OCTA>.|\n           /* Ignore everything after \0 */
 

 /* ====================================================================== */
 /* ====[                3.7 - Identificadores (nomes)               ]==== */
 /* ====================================================================== */

 /* ====================================================================== */
 /* ====[                      to catagorize                         ]==== */
 /* ====================================================================== */

">=" return tGE; 
"<=" return tLE; 
"==" return tEQ; 
"!=" return tNE;
"&&" return tAND;
"||" return tOR;
"~"  return tNOT;


"->" return tARROW;

[A-Za-z][A-Za-z0-9_]*  {
    yylval.s = new std::string(yytext);
    std::transform(yylval.s->begin(), yylval.s->end(), yylval.s->begin(), ::tolower);
    return tIDENTIFIER;
}

[-()<>=+*/%;{}.@\[\],]       return *yytext;

[ \t\n\r]+               ; /* ignore whitespace */

.                      yyerror("Unknown character");

%%
