#ifndef __MML_AST_STOP_NODE_H__
#define __MML_AST_STOP_NODE_H__

#include <cdk/ast/basic_node.h>
#include <cdk/ast/integer_node.h>

namespace mml {

  class stop_node: public cdk::basic_node {
    int _stop_val;
    

  public:
    stop_node(int lineno, int stop_val) :
        cdk::basic_node(lineno), _stop_val(stop_val) {
    }

    stop_node(int lineno) :
        cdk::basic_node(lineno), _stop_val(1) {
    }

  public:
    int stop_val() {
      return _stop_val;
    }

  public:
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_stop_node(this, level);
    }

  };

} // mml

#endif
