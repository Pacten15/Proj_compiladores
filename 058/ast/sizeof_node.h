#ifndef __MML_AST_SIZEOF_H__
#define __MML_AST_SIZEOF_H__

#include <cdk/ast/expression_node.h>

namespace mml {

  class sizeof_node: public cdk::expression_node {
    cdk::expression_node *_argument;

  public:
    sizeof_node(int lineno, cdk::expression_node *argument) :
        cdk::expression_node(lineno), _argument(argument) {
    }

  public:
    cdk::expression_node* argument() {
      return _argument;
    }

  public:
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_sizeof_node(this, level);
    }

  };

} // mml

#endif
