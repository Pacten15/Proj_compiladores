#ifndef __MML_AST_INDEX_NODE_H__
#define __MML_AST_INDEX_NODE_H__

#include <cdk/ast/lvalue_node.h>

namespace mml {

  class pointer_to_index_node: public cdk::lvalue_node {
    cdk::expression_node *_base;
    cdk::expression_node *_index;

  public:
    pointer_to_index_node(int lineno, cdk::expression_node *base, cdk::expression_node *index) :
        cdk::lvalue_node(lineno), _base(base), _index(index) {
    }

  public:
    cdk::expression_node* base() {
      return _base;
    }
    cdk::expression_node* index() {
      return _index;
    }

  public:
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_pointer_to_index_node(this, level);
    }

  };

} // mml

#endif