#ifndef __MML_AST_FUNCTION_CALL_H__
#define __MML_AST_FUNCTION_CALL_H__

#include <string>
#include <cdk/ast/basic_node.h>
#include <cdk/ast/sequence_node.h>
#include <cdk/ast/nil_node.h>
#include <cdk/ast/expression_node.h>

namespace mml {

  //
  // Class for describing function call nodes.
  //
  // If _arguments is null, them the node is either a call to a function with
  // no arguments (or in which none of the default arguments is present) or
  // an access to a variable.
  //
  class function_call_node: public cdk::expression_node {
    cdk::expression_node *_expression;
    cdk::sequence_node *_arguments;
    bool _recursive;

  public:
    function_call_node(int lineno, cdk::expression_node *expression, cdk::sequence_node *arguments, bool recursive = false) :
        cdk::expression_node(lineno), _expression(expression), _arguments(arguments), _recursive(recursive) {
    }

  public:

    cdk::expression_node* expression() {
      return _expression;
    }

    cdk::sequence_node* arguments() {
      return _arguments;
    }
    cdk::expression_node *argument(size_t ix) {
      return dynamic_cast<cdk::expression_node*>(_arguments->node(ix));
    }

    bool recursive() {
      return _recursive;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_function_call_node(this, level);
    }

  };

} // mml

#endif
