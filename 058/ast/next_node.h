#ifndef __MML_AST_NEXT_NODE_H__
#define __MML_AST_NEXT_NODE_H__

#include <cdk/ast/basic_node.h>
#include <cdk/ast/integer_node.h>

namespace mml {

  class next_node: public cdk::basic_node {
    int _next_val;

  public:
    next_node(int lineno, int next_val) :
        cdk::basic_node(lineno), _next_val(next_val) {
    }

    next_node(int lineno) :
        cdk::basic_node(lineno), _next_val(1) {

    }

  public:
    int next_val() {
      return _next_val;
    }

  public:
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_next_node(this, level);
    }

  };

} // mml

#endif

