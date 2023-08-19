%{
//-- don't change *any* of these: if you do, you'll break the compiler.
#include <algorithm>
#include <memory>
#include <cstring>
#include <cdk/compiler.h>
#include <cdk/types/types.h>
#include ".auto/all_nodes.h"
#define LINE                         compiler->scanner()->lineno()
#define yylex()                      compiler->scanner()->scan()
#define yyerror(compiler, s)         compiler->scanner()->error(s)
//-- don't change *any* of these --- END!
%}

%parse-param {std::shared_ptr<cdk::compiler> compiler}

%union {
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
};

%token tIF tBEGIN tEND 
%token tFOREIGN tFORWARD tPUBLIC tAUTO tPRIVATE 
%token tINPUT tPRINT tPRINTLN
%token tWHILE tSTOP tNEXT tRETURN
%token tSIZEOF
%token tTYPE_STRING tTYPE_INTEGER tTYPE_DOUBLE tTYPE_VOID
%token tARROW

%token <i> tINTEGER
%token <d> tDOUBLE
%token <s> tSTRING 
%token <expression> tNULLPTR
%token <s> tIDENTIFIER 

%type <s> string
%type <node> main_program declaration instruction cond_inst iter_inst elif  
%type <vardec> arg
%type <sequence> args
%type <sequence> file declarations opt_decs instructions expressions opt_expressions
%type <expression> expression opt_init func_def
%type <type> type auto
%type <type_vec> types
%type <lvalue> lval
%type <i> qualifier
%type <block> block

%right '=' tADDRESS 
%left tOR
%left tAND
%nonassoc tNOT
%left tEQ tNE
%left '<' '>' tLE tGE
%left '+' '-'
%left '*' '/' '%' '@'
%nonassoc tUNARY
%nonassoc '(' '[' 

%nonassoc tIFX
%nonassoc tELIF tELSE

%{
//-- The rules below will be included in yyparse, the main parsing function.
%}
%%

file          : opt_decs              { compiler->ast($$ = $1); } 
              | opt_decs main_program { compiler->ast($$ = new cdk::sequence_node(LINE, $2, $1)); }
              ; 

main_program  : tBEGIN declarations instructions tEND { $$ = new mml::function_definition_node(LINE, nullptr, nullptr, new mml::block_node(LINE, $2, $3), true); } 
              | tBEGIN declarations              tEND { $$ = new mml::function_definition_node(LINE, nullptr, nullptr, new mml::block_node(LINE, $2, nullptr), true); } 
              | tBEGIN              instructions tEND { $$ = new mml::function_definition_node(LINE, nullptr, nullptr, new mml::block_node(LINE, nullptr, $2), true); } 
              | tBEGIN                           tEND { $$ = new mml::function_definition_node(LINE, nullptr, nullptr, new mml::block_node(LINE, nullptr, nullptr), true); } 
              ;

declaration   :           type tIDENTIFIER     opt_init   ';' { $$ = new mml::variable_declaration_node(LINE, tPRIVATE, $1,      *$2, $3); delete $2; }
              |           auto tIDENTIFIER '=' expression ';' { $$ = new mml::variable_declaration_node(LINE, tPRIVATE, $1,      *$2, $4); delete $2; } 
              | qualifier type tIDENTIFIER     opt_init   ';' { $$ = new mml::variable_declaration_node(LINE, $1,       $2,      *$3, $4); delete $3; }
              | qualifier auto tIDENTIFIER '=' expression ';' { $$ = new mml::variable_declaration_node(LINE, $1,       $2, *$3, $5); delete $3; }
              | qualifier      tIDENTIFIER '=' expression ';' { $$ = new mml::variable_declaration_node(LINE, $1,       cdk::primitive_type::create(0, cdk::TYPE_UNSPEC), *$2, $4); delete $2; }
              ;

declarations  :              declaration { $$ = new cdk::sequence_node(LINE, $1); }
              | declarations declaration { $$ = new cdk::sequence_node(LINE, $2, $1); }
              ;

opt_decs      :              { $$ = NULL; }
              | declarations { $$ = $1;   }
              ;

qualifier     : tFOREIGN { $$ = tFOREIGN; }
              | tFORWARD { $$ = tFORWARD; }
              | tPUBLIC  { $$ = tPUBLIC;  }
              ;

type          : tTYPE_INTEGER { $$ = cdk::primitive_type::create(4, cdk::TYPE_INT); }
              | tTYPE_DOUBLE  { $$ = cdk::primitive_type::create(8, cdk::TYPE_DOUBLE); }
              | tTYPE_STRING  { $$ = cdk::primitive_type::create(4, cdk::TYPE_STRING); }
              | tTYPE_VOID    { $$ = cdk::primitive_type::create(4, cdk::TYPE_VOID); }
              | '[' type ']'       { $$ = cdk::reference_type::create(4, $2); }
              | type '<'       '>' { $$ = cdk::functional_type::create($1); }
              | type '<' types '>' { $$ = cdk::functional_type::create(*$3, $1); delete $3; }
              ;

auto          : tAUTO { $$ = cdk::primitive_type::create(8, cdk::TYPE_UNSPEC); }
              ;

types         :           type { $$ = new std::vector<std::shared_ptr<cdk::basic_type>>(); $$->push_back($1); }
              | types ',' type { $$ = $1; $$->push_back($3); }
              ;

opt_init      :                     { $$ = nullptr; }
              | '=' expression      { $$ = $2; }
              ;

instruction   : expression ';'         { $$ = new mml::evaluation_node(LINE, $1);      }
              | expressions tPRINT     { $$ = new mml::print_node(LINE, $1);           }
              | expressions tPRINTLN   { $$ = new mml::print_node(LINE, $1, true);     }
              | tSTOP              ';' { $$ = new mml::stop_node(LINE);                }
              | tSTOP   tINTEGER   ';' { $$ = new mml::stop_node(LINE, $2);            } 
              | tNEXT              ';' { $$ = new mml::next_node(LINE);                }
              | tNEXT   tINTEGER   ';' { $$ = new mml::next_node(LINE, $2);            }
              | tRETURN expression ';' { $$ = new mml::return_node(LINE, $2);          }     
              | cond_inst              { $$ = $1;                                      }
              | iter_inst              { $$ = $1;                                      }
              | block                  { $$ = $1;                                      }
              ;

cond_inst     : tIF '(' expression ')' instruction %prec tIFX     { $$ = new mml::if_node(LINE, $3, $5);          }
              | tIF '(' expression ')' instruction elif           { $$ = new mml::if_else_node(LINE, $3, $5, $6); }

elif          : tELSE instruction                                 { $$ = $2; }
              | tELIF '(' expression ')' instruction %prec tIFX   { $$ = new mml::if_node(LINE, $3, $5); }
              | tELIF '(' expression ')' instruction elif         { $$ = new mml::if_else_node(LINE, $3, $5, $6); }
              ;

iter_inst     : tWHILE '(' expression ')' instruction                { $$ = new mml::while_node(LINE, $3, $5);       }
              ;

instructions  :              instruction { $$ = new cdk::sequence_node(LINE, $1); }
              | instructions instruction { $$ = new cdk::sequence_node(LINE, $2, $1); }
              ;
     
expression    : tINTEGER                             { $$ = new cdk::integer_node(LINE, $1);                        }
              | tDOUBLE                              { $$ = new cdk::double_node(LINE, $1);                         }
	            | string                               { $$ = new cdk::string_node(LINE, $1);                         }
              | tNULLPTR                             { $$ = new mml::nullptr_node(LINE);                            }
              | '+' expression %prec tUNARY          { $$ = new mml::identity_node(LINE, $2);                       }
              | '-' expression %prec tUNARY          { $$ = new cdk::neg_node(LINE, $2);                            }
              | tNOT expression                      { $$ = new cdk::not_node(LINE, $2);                            }
              | expression '+'  expression           { $$ = new cdk::add_node(LINE, $1, $3);                        }
              | expression '-'  expression           { $$ = new cdk::sub_node(LINE, $1, $3);                        }
              | expression '*'  expression           { $$ = new cdk::mul_node(LINE, $1, $3);                        }
              | expression '/'  expression           { $$ = new cdk::div_node(LINE, $1, $3);                        }
              | expression '%'  expression           { $$ = new cdk::mod_node(LINE, $1, $3);                        }
              | expression '<'  expression           { $$ = new cdk::lt_node(LINE, $1, $3);                         }
              | expression '>'  expression           { $$ = new cdk::gt_node(LINE, $1, $3);                         }
              | expression tGE  expression           { $$ = new cdk::ge_node(LINE, $1, $3);                         }
              | expression tLE  expression           { $$ = new cdk::le_node(LINE, $1, $3);                         }
              | expression tNE  expression           { $$ = new cdk::ne_node(LINE, $1, $3);                         }
              | expression tEQ  expression           { $$ = new cdk::eq_node(LINE, $1, $3);                         }
              | expression tOR  expression           { $$ = new cdk::or_node(LINE, $1, $3);                         }
              | expression tAND expression           { $$ = new cdk::and_node(LINE, $1, $3);                        }
              | lval                                 { $$ = new cdk::rvalue_node(LINE, $1);                         }
              | lval '=' expression                  { $$ = new cdk::assignment_node(LINE, $1, $3);                 }
              | tINPUT                               { $$ = new mml::input_node(LINE);                              }
              | tSIZEOF '(' expression ')'           { $$ = new mml::sizeof_node(LINE, $3);                         }
              | lval tADDRESS  %prec tUNARY          { $$ = new mml::address_of_node(LINE, $1);                     }
              | '[' expression ']'                   { $$ = new mml::stack_alloc_node(LINE, $2);                    }
              | expression '(' opt_expressions ')'   { $$ = new mml::function_call_node(LINE, $1, $3);              }
              | '@'  '(' opt_expressions ')'         { $$ = new mml::function_call_node(LINE, nullptr, $3, true);   }
              | '(' expression ')'                   { $$ = $2;                                                     }
              | func_def                             { $$ = $1;                                                     }                                   
              ;

expressions   :                 expression { $$ = new cdk::sequence_node(LINE, $1);     }
              | expressions ',' expression { $$ = new cdk::sequence_node(LINE, $3, $1); }
              ;

opt_expressions :                     { $$ = new cdk::sequence_node(LINE); }
                | expressions         { $$ = $1; }
                ;  

lval          : tIDENTIFIER { $$ = new cdk::variable_node(LINE, $1); }
              | expression '[' expression ']' {$$ = new mml::pointer_to_index_node(LINE, $1, $3); }
              ;

arg           : type tIDENTIFIER { $$ = new mml::variable_declaration_node(LINE, tPRIVATE, $1, *$2, nullptr); }
              ;

args          : /*empty*/            { $$ = new cdk::sequence_node(LINE); }
              |          arg { $$ = new cdk::sequence_node(LINE, $1);     }
              | args ',' arg { $$ = new cdk::sequence_node(LINE, $3, $1); }
              ;  

block         : '{' declarations instructions '}' { $$ = new mml::block_node(LINE, $2, $3); }
              | '{' declarations              '}' { $$ = new mml::block_node(LINE, $2, nullptr); }
              | '{'              instructions '}' { $$ = new mml::block_node(LINE, nullptr, $2); }
              | '{'                           '}' { $$ = new mml::block_node(LINE, nullptr, nullptr); }
              ;

func_def      : '(' args ')' tARROW type block { $$ = new mml::function_definition_node(LINE, $2, $5, $6); }
              | '(' args ')' tARROW auto block { $$ = new mml::function_definition_node(LINE, $2, $5, $6); }
              ;

string        : tSTRING        { $$ = $1; }
              | string tSTRING { $$ = $1; $$->append(*$2); delete $2; }
              ;

%%
