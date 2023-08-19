#ifndef __MML_AST_EVALUATION_NODE_H__
#define __MML_AST_EVALUATION_NODE_H__

#include <cdk/ast/expression_node.h>

namespace mml {

  /**
   * Class for describing evaluation nodes.
   */
  class evaluation_node: public cdk::basic_node {
    cdk::expression_node *_expression;

  public:
    inline evaluation_node(int lineno, cdk::expression_node *expression) :
        cdk::basic_node(lineno), _expression(expression) {
    }

  public:
    inline cdk::expression_node *expression() {
      return _expression;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_evaluation_node(this, level);
    }

  };

} // mml

#endif
