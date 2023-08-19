#ifndef __MML_AST_FUNCTION_DEFINITION_H__
#define __MML_AST_FUNCTION_DEFINITION_H__

#include <string>
#include <vector>
#include <cdk/ast/typed_node.h>
#include <cdk/ast/sequence_node.h>
#include "ast/block_node.h"
#include "ast/variable_declaration_node.h"

namespace mml {

  //
  // Class for describing function definitions.
  //
  class function_definition_node: public cdk::expression_node {
    cdk::sequence_node *_arguments;
    mml::block_node *_block;
    bool _is_main;

  public:

    function_definition_node(int lineno, cdk::sequence_node *arguments, std::shared_ptr<cdk::basic_type> return_type, mml::block_node *block,
                             bool is_main = false) :
                            cdk::expression_node(lineno), _arguments(arguments), _block(block), _is_main(is_main) {
      std::vector<std::shared_ptr<cdk::basic_type>> input_types;
      if (is_main) {
        type(cdk::functional_type::create(input_types, cdk::primitive_type::create(4, cdk::TYPE_INT)));
      } else {
        for (cdk::basic_node *node : arguments->nodes()) {    
          mml::variable_declaration_node *var_dec_node = (mml::variable_declaration_node*) node;
          input_types.push_back(var_dec_node->type());
        }
        type(cdk::functional_type::create(input_types, return_type));
      }
      
    }

  public:
    bool is_main() {
      return _is_main;
    }
    cdk::sequence_node* arguments() {
      return _arguments;
    }
    cdk::typed_node* argument(size_t ax) {
      return dynamic_cast<cdk::typed_node*>(_arguments->node(ax));
    }
    mml::block_node* block() {
      return _block;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_function_definition_node(this, level);
    }

  };

} // mml

#endif
