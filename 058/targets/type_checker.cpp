#include <string>
#include "targets/type_checker.h"
#include ".auto/all_nodes.h"  // automatically generated
#include <cdk/types/primitive_type.h>

// must come after other #includes
#include "mml_parser.tab.h"

#define ASSERT_UNSPEC { if (node->type() != nullptr && !node->is_typed(cdk::TYPE_UNSPEC)) return; }

static bool is_ID(cdk::typed_node *const node) {
  return node->is_typed(cdk::TYPE_INT) || node->is_typed(cdk::TYPE_DOUBLE);
}

//---------------------------------------------------------------------------

void mml::type_checker::do_sequence_node(cdk::sequence_node *const node, int lvl) {
  for (size_t i = 0; i < node->size(); i++)
    node->node(i)->accept(this, lvl);
}

//---------------------------------------------------------------------------

void mml::type_checker::do_nil_node(cdk::nil_node *const node, int lvl) {
  // EMPTY
}
void mml::type_checker::do_data_node(cdk::data_node *const node, int lvl) {
  // EMPTY
}

//---------------------------------------------------------------------------

void mml::type_checker::do_integer_node(cdk::integer_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

void mml::type_checker::do_double_node(cdk::double_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
}

void mml::type_checker::do_string_node(cdk::string_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(cdk::primitive_type::create(4, cdk::TYPE_STRING));
}

void mml::type_checker::do_nullptr_node(mml::nullptr_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(cdk::reference_type::create(4, nullptr));
}

//---------------------------------------------------------------------------

// TODO

void mml::type_checker::processUnaryExpression(cdk::unary_operation_node *const node, int lvl) {
  node->argument()->accept(this, lvl + 2);
  if (!node->argument()->is_typed(cdk::TYPE_INT)) throw std::string("wrong type in argument of unary expression");

  // in MML, expressions are always int
  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

void mml::type_checker::do_identity_node(mml::identity_node * const node, int lvl) { //? other verifications?
  processUnaryExpression(node, lvl);
  if (!is_ID(node)) {
    throw std::string("invalid type in identity");
  }
}

void mml::type_checker::do_neg_node(cdk::neg_node *const node, int lvl) {
  processUnaryExpression(node, lvl);
}

void mml::type_checker::do_not_node(cdk::not_node *const node, int lvl) {
  processUnaryExpression(node, lvl);
}

//---------------------------------------------------------------------------

//protected:
void mml::type_checker::processIDExpression(cdk::binary_operation_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  node->right()->accept(this, lvl + 2);

  if (node->left()->is_typed(cdk::TYPE_DOUBLE) && node->right()->is_typed(cdk::TYPE_DOUBLE)) {
    node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
  } else if (node->left()->is_typed(cdk::TYPE_DOUBLE) && node->right()->is_typed(cdk::TYPE_INT)) {
    node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
  } else if (node->left()->is_typed(cdk::TYPE_INT) && node->right()->is_typed(cdk::TYPE_DOUBLE)) {
    node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
  } else if (node->left()->is_typed(cdk::TYPE_INT) && node->right()->is_typed(cdk::TYPE_INT)) {
    node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
  } else if (node->left()->is_typed(cdk::TYPE_UNSPEC) && node->right()->is_typed(cdk::TYPE_UNSPEC)) {
    node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
    node->left()->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
    node->right()->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
  } else {
    throw std::string("wrong types in binary expression");
  }
}

void mml::type_checker::do_mul_node(cdk::mul_node *const node, int lvl) {
  processIDExpression(node, lvl);
}
void mml::type_checker::do_div_node(cdk::div_node *const node, int lvl) {
  processIDExpression(node, lvl);
}

//---------------------------------------------------------------------------

//protected:
void mml::type_checker::processPIDExpression(cdk::binary_operation_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  node->right()->accept(this, lvl + 2);

  if (node->left()->is_typed(cdk::TYPE_DOUBLE) && node->right()->is_typed(cdk::TYPE_DOUBLE)) {
    node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
  } else if (node->left()->is_typed(cdk::TYPE_DOUBLE) && node->right()->is_typed(cdk::TYPE_INT)) {
    node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
  } else if (node->left()->is_typed(cdk::TYPE_INT) && node->right()->is_typed(cdk::TYPE_DOUBLE)) {
    node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
  } else if (node->left()->is_typed(cdk::TYPE_POINTER) && node->right()->is_typed(cdk::TYPE_INT)) {
    node->type(node->left()->type());
  } else if (node->left()->is_typed(cdk::TYPE_INT) && node->right()->is_typed(cdk::TYPE_POINTER)) {
    node->type(node->right()->type());
  } else if (node->left()->is_typed(cdk::TYPE_INT) && node->right()->is_typed(cdk::TYPE_INT)) {
    node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
  } else if (node->left()->is_typed(cdk::TYPE_UNSPEC) && node->right()->is_typed(cdk::TYPE_UNSPEC)) {
    node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
    node->left()->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
    node->right()->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
  } else {
    throw std::string("wrong types in binary expression");
  }
}

void mml::type_checker::do_add_node(cdk::add_node *const node, int lvl) {
  processPIDExpression(node, lvl);
}
void mml::type_checker::do_sub_node(cdk::sub_node *const node, int lvl) {
  processPIDExpression(node, lvl);
}

//---------------------------------------------------------------------------

//protected:
void mml::type_checker::processScalarLogicalExpression(cdk::binary_operation_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  if (!node->left()->is_typed(cdk::TYPE_INT)) {
    throw std::string("integer expression expected in binary logical expression (left)");
  }

  node->right()->accept(this, lvl + 2);
  if (!node->right()->is_typed(cdk::TYPE_INT)) {
    throw std::string("integer expression expected in binary logical expression (right)");
  }

  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

void mml::type_checker::do_lt_node(cdk::lt_node *const node, int lvl) {
  processScalarLogicalExpression(node, lvl);
}
void mml::type_checker::do_le_node(cdk::le_node *const node, int lvl) {
  processScalarLogicalExpression(node, lvl);
}
void mml::type_checker::do_ge_node(cdk::ge_node *const node, int lvl) {
  processScalarLogicalExpression(node, lvl);
}
void mml::type_checker::do_gt_node(cdk::gt_node *const node, int lvl) {
  processScalarLogicalExpression(node, lvl);
}

//---------------------------------------------------------------------------

//protected:
void mml::type_checker::processBooleanLogicalExpression(cdk::binary_operation_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  if (!node->left()->is_typed(cdk::TYPE_INT)) {
    throw std::string("integer expression expected in binary expression");
  }

  node->right()->accept(this, lvl + 2);
  if (!node->right()->is_typed(cdk::TYPE_INT)) {
    throw std::string("integer expression expected in binary expression");
  }

  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

void mml::type_checker::do_and_node(cdk::and_node *const node, int lvl) {
  processBooleanLogicalExpression(node, lvl);
}
void mml::type_checker::do_or_node(cdk::or_node *const node, int lvl) {
  processBooleanLogicalExpression(node, lvl);
}

//---------------------------------------------------------------------------

//protected:
void mml::type_checker::processGeneralLogicalExpression(cdk::binary_operation_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  node->right()->accept(this, lvl + 2);
  if (node->left()->type() != node->right()->type()) {
    throw std::string("same type expected on both sides of equality operator");
  }
  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

void mml::type_checker::do_ne_node(cdk::ne_node *const node, int lvl) {
  processGeneralLogicalExpression(node, lvl);
}
void mml::type_checker::do_eq_node(cdk::eq_node *const node, int lvl) {
  processGeneralLogicalExpression(node, lvl);
}

//---------------------------------------------------------------------------

void mml::type_checker::processIntOnlyExpression(cdk::binary_operation_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  if (!node->left()->is_typed(cdk::TYPE_INT)) {
    throw std::string("integer expression expected in binary operator (left)");
  }

  node->right()->accept(this, lvl + 2);
  if (!node->right()->is_typed(cdk::TYPE_INT)) {
    throw std::string("integer expression expected in binary operator (right)");
  }

  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

void mml::type_checker::do_mod_node(cdk::mod_node *const node, int lvl) {
  processIntOnlyExpression(node, lvl);
}

//---------------------------------------------------------------------------

void mml::type_checker::do_variable_node(cdk::variable_node *const node, int lvl) {
  ASSERT_UNSPEC;
  const std::string &id = node->name();
  std::shared_ptr<mml::symbol> symbol = _symtab.find(id);

  if (symbol != nullptr) {
    node->type(symbol->type());
  } else {
    throw id;
  }
}

void mml::type_checker::do_rvalue_node(cdk::rvalue_node *const node, int lvl) {
  ASSERT_UNSPEC;
  try {
    node->lvalue()->accept(this, lvl);
    node->type(node->lvalue()->type());
  } catch (const std::string &id) {
    throw "undeclared variable '" + id + "'";
  }
}

void mml::type_checker::do_assignment_node(cdk::assignment_node *const node, int lvl) {
  ASSERT_UNSPEC;

  node->lvalue()->accept(this, lvl + 4);
  _parent->set_var_dec_type(node->lvalue()->type());
  node->rvalue()->accept(this, lvl + 4);

  if (node->lvalue()->is_typed(cdk::TYPE_INT)) {
    if (node->rvalue()->is_typed(cdk::TYPE_INT)) {
      node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
    } else if (node->rvalue()->is_typed(cdk::TYPE_UNSPEC)) {
      node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
      node->rvalue()->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
    } else {
      throw std::string("wrong assignment to integer");
    }
  } else if (node->lvalue()->is_typed(cdk::TYPE_POINTER)) {

    //TODO: check pointer level

    if (node->rvalue()->is_typed(cdk::TYPE_POINTER)) {
      node->type(node->rvalue()->type());
    //TODO } else if (nullptr) {
    } else if (node->rvalue()->is_typed(cdk::TYPE_UNSPEC)) {
      node->type(cdk::primitive_type::create(4, cdk::TYPE_ERROR));
      node->rvalue()->type(cdk::primitive_type::create(4, cdk::TYPE_ERROR));
    } else {
      throw std::string("wrong assignment to pointer");
    }

  } else if (node->lvalue()->is_typed(cdk::TYPE_DOUBLE)) {

    if (node->rvalue()->is_typed(cdk::TYPE_DOUBLE) || node->rvalue()->is_typed(cdk::TYPE_INT)) {
      node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
    } else if (node->rvalue()->is_typed(cdk::TYPE_UNSPEC)) {
      node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
      node->rvalue()->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
    } else {
      throw std::string("wrong assignment to real");
    }

  } else if (node->lvalue()->is_typed(cdk::TYPE_STRING)) {

    if (node->rvalue()->is_typed(cdk::TYPE_STRING)) {
      node->type(cdk::primitive_type::create(4, cdk::TYPE_STRING));
    } else if (node->rvalue()->is_typed(cdk::TYPE_UNSPEC)) {
      node->type(cdk::primitive_type::create(4, cdk::TYPE_STRING));
      node->rvalue()->type(cdk::primitive_type::create(4, cdk::TYPE_STRING));
    } else {
      throw std::string("wrong assignment to string");
    }

    } else if (node->lvalue()->is_typed(cdk::TYPE_FUNCTIONAL)) {

    if (node->rvalue()->is_typed(cdk::TYPE_FUNCTIONAL)) {
      auto lvalue_type = cdk::functional_type::cast(node->rvalue()->type());
      auto rvalue_type = cdk::functional_type::cast(node->rvalue()->type());
      if (lvalue_type->output()->component(0)->name() != rvalue_type->output()->component(0)->name()) {
        throw std::string("mismatch of return type between function's variable and it's definition.");
      } else if (lvalue_type->input()->length() != rvalue_type->input()->length()) {
        throw std::string("mismatch of number of arguments between function's variable and it's definition.");
      }
      for (size_t i = 0; i < lvalue_type->input()->length(); i++) {
        if (lvalue_type->input()->component(i)->name() != rvalue_type->input()->component(i)->name()) {
          throw std::string("mismatch of type of the " + std::to_string(i+1) + "th argument between function's variable and it's definition");
        }
      }
      
      cdk::variable_node *var = (cdk::variable_node *) node->lvalue();

      auto symbol = _symtab.find(var->name());
      if (symbol == nullptr) {
        std::cerr << node->lineno() << "symbol must exist" << std::endl;
        exit(1);
      } else {
        symbol->set_referenced_func_id(_function->name());
      }

      node->type(node->rvalue()->type());
    } else {
      throw std::string("wrong assignment to function");
    }
  } else {
    throw std::string("wrong types in assignment");
  }
}

//---------------------------------------------------------------------------

void mml::type_checker::do_evaluation_node(mml::evaluation_node *const node, int lvl) {
  node->expression()->accept(this, lvl + 2);
}

void mml::type_checker::do_print_node(mml::print_node *const node, int lvl) {
  node->arguments()->accept(this, lvl + 2);
}

void mml::type_checker::do_input_node(mml::input_node * const node, int lvl) {
  node->type(cdk::primitive_type::create(0, cdk::TYPE_UNSPEC));
}

//---------------------------------------------------------------------------

void mml::type_checker::do_while_node(mml::while_node *const node, int lvl) {
  node->condition()->accept(this, lvl + 2);
  node->block()->accept(this, lvl + 2);
}

void mml::type_checker::do_next_node(mml::next_node * const node, int lvl) {
  //EMPTY
}

void mml::type_checker::do_stop_node(mml::stop_node * const node, int lvl) {
  //EMPTY
}

//---------------------------------------------------------------------------

void mml::type_checker::do_if_node(mml::if_node *const node, int lvl) {
  node->condition()->accept(this, lvl + 4);
  if (!node->condition()->is_typed(cdk::TYPE_INT)) throw std::string("expected integer condition");
}

void mml::type_checker::do_if_else_node(mml::if_else_node *const node, int lvl) {
  node->condition()->accept(this, lvl + 4);
  if (!node->condition()->is_typed(cdk::TYPE_INT)) throw std::string("expected integer condition");
}

//---------------------------------------------------------------------------

void mml::type_checker::do_return_node(mml::return_node * const node, int lvl) {
  
  if (!_function) {
    throw std::string("ICE(type_checker/return_node): _function was not set\n");
    exit(1);
  }

  if (node->retval()) {
    if (_function->type() != nullptr && _function->is_typed(cdk::TYPE_VOID))
      throw std::string("return specified for void function.");

    node->retval()->accept(this, lvl + 2);


    if (_inBlockReturnType == nullptr) {
      _inBlockReturnType = node->retval()->type();
    } else {
      if (_inBlockReturnType != node->retval()->type()) {
        _function->set_type(cdk::primitive_type::create(0, cdk::TYPE_ERROR));  // probably irrelevant
        throw std::string("all return statements in a function must return the same type.");
      }
    }

    std::shared_ptr<cdk::functional_type> func_type = std::static_pointer_cast<cdk::functional_type>(_function->type());
    std::shared_ptr<cdk::basic_type> return_type = func_type->output()->component(0);
    if (return_type->name() == cdk::TYPE_INT) {
      if (!node->retval()->is_typed(cdk::TYPE_INT)) throw std::string("wrong type for initializer (integer expected).");
    } else if (return_type->name() == cdk::TYPE_DOUBLE) {
      if (!node->retval()->is_typed(cdk::TYPE_INT) && !node->retval()->is_typed(cdk::TYPE_DOUBLE)) {
        throw std::string("wrong type for initializer (integer or double expected).");
      }
    } else if (return_type->name() == cdk::TYPE_STRING) {
      if (!node->retval()->is_typed(cdk::TYPE_STRING)) {
        throw std::string("wrong type for initializer (string expected).");
      }
    }else if (return_type->name() == cdk::TYPE_POINTER) { // TODO
      //DAVID: FIXME: trouble!!!
      /*
      int ft = 0, rt = 0;
      auto ftype = _function->;
      while (ftype == cdk::TYPE_POINTER) {
        ft++;
        ftype = cdk::reference_type::cast(ftype)->referenced();
      }
      auto rtype = node->retval()->type();
      while (rtype != nullptr && rtype->name() == cdk::TYPE_POINTER) {
        rt++;
        rtype = cdk::reference_type::cast(rtype)->referenced();
      }
      std::cout << "FUNCT NAME " << _function->name() << " --- " << ft << " -- " << ftype->name() << std::endl;
      std::cout << "FUNCT TYPE " << cdk::to_string(_function->type()) << " --- " << ft << " -- " << ftype->name() << cdk::to_string(ftype) << std::endl;
      std::cout << "RETVAL TYPE " << cdk::to_string(node->retval()->type()) << " --- " << rt << " -- " << cdk::to_string(rtype)
          << std::endl;

      bool compatible = (ft == rt) && (rtype == nullptr ||( ftype != nullptr && (cdk::to_string(ftype) == cdk::to_string(rtype))));
      if (!compatible) throw std::string("wrong type for return expression (pointer expected).");
      */
    } else if (return_type->name() == cdk::TYPE_FUNCTIONAL) { // TODO
      throw std::string("return TYPE_FUNCTIONAL not yet implemented");
    } else {
      throw std::string("unknown type for initializer.");
    }
  }
 
}

//---------------------------------------------------------------------------

void mml::type_checker::do_block_node(mml::block_node * const node, int lvl) {
  // EMPTY
}

//---------------------------------------------------------------------------

void mml::type_checker::do_stack_alloc_node(mml::stack_alloc_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->argument()->accept(this, lvl + 2);
  if (!node->argument()->is_typed(cdk::TYPE_INT)) {
    throw std::string("integer expression expected in allocation expression");
  }
  node->type(_parent->var_dec_type()); // has to be reference to not break type checking
}

void mml::type_checker::do_pointer_to_index_node(mml::pointer_to_index_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->base()->accept(this, lvl + 2);
  node->index()->accept(this, lvl + 2);

  if (!node->base()->is_typed(cdk::TYPE_POINTER)) {
    throw std::string("pointer expression expected in pointer indexing");
  }

  if (!node->index()->is_typed(cdk::TYPE_INT)) {
    throw std::string("integer expected in index");
  }
  
  auto ref = std::dynamic_pointer_cast<cdk::reference_type>(node->base()->type());
  node->type(ref->referenced());
}

void mml::type_checker::do_address_of_node(mml::address_of_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->lvalue()->accept(this, lvl + 2);
  node->type(cdk::reference_type::create(4, node->lvalue()->type()));
}

//---------------------------------------------------------------------------

void mml::type_checker::do_function_definition_node(mml::function_definition_node * const node, int lvl) {


  _inBlockReturnType = nullptr;
  
  auto func_var_symbol = _symtab.find(_parent->func_var_id());

  if (!_parent->can_give_func_id()) {
    if (func_var_symbol != nullptr && func_var_symbol->forward_is_done()) {
      _parent->set_new_symbol(_symtab.find(func_var_symbol->referenced_func_id()));
    } else {
      _parent->set_new_symbol(_symtab.find(_parent->current_func_id()));
    }
    return;
  }
  
  // remember symbol so that args know
  std::string func_id;
  if (func_var_symbol != nullptr && func_var_symbol->forward()) {
    _parent->disallow_func_id_giving();
    func_id = func_var_symbol->referenced_func_id();
  } else if (node->is_main()) {
    func_id = _parent->give_main_func_id();
  } else {
    func_id = _parent->give_func_id();
  }
  auto function = mml::make_symbol(node->type(), func_id, 0, false, 0, false, true, false, false);

  // fill up symbol arguments
  if (node->arguments() != nullptr) {
    std::vector < std::shared_ptr < cdk::basic_type >> argtypes;
    for (size_t ax = 0; ax < node->arguments()->size(); ax++)
      argtypes.push_back(node->argument(ax)->type());
    function->set_argument_types(argtypes);
  }
  
  _symtab.insert(function->name(), function);
  _parent->set_new_symbol(function);

  _parent->set_last_func_symbol(_function);
  _function = function;
}

void mml::type_checker::do_function_call_node(mml::function_call_node * const node, int lvl) {
  ASSERT_UNSPEC;

  std::string id;
  if (node->recursive()) {
    id = _function->name();
  } else {
    cdk::rvalue_node *rvalue = (cdk::rvalue_node*) node->expression();
    cdk::variable_node *caller = (cdk::variable_node*) rvalue->lvalue(); 
    id = caller->name();
  }

  auto symbol = _symtab.find(id);
  if (symbol == nullptr) throw std::string("symbol '" + id + "' is undeclared.");
  if (!symbol->isFunction()) throw std::string("symbol '" + id + "' is not a function.");

  std::shared_ptr<cdk::functional_type> symbol_type = std::static_pointer_cast<cdk::functional_type>(symbol->type());

  node->type(symbol_type->output()->component(0));


  if (node->arguments()->size() == symbol_type->input()->components().size()) {
    node->arguments()->accept(this, lvl + 4);
    for (size_t ax = 0; ax < node->arguments()->size(); ax++) {
      if (node->argument(ax)->type()->name() == symbol_type->input()->component(ax)->name()) continue;
      if (symbol_type->input()->component(ax)->name() == cdk::TYPE_DOUBLE && node->argument(ax)->is_typed(cdk::TYPE_INT)) continue;
      throw std::string("type mismatch for argument " + std::to_string(ax + 1) + " of '" + id + "'.");
    }
  } else {
    throw std::string(
        "number of arguments in call (" + std::to_string(node->arguments()->size()) + ") must match declaration ("
            + std::to_string(symbol_type->input()->components().size()) + ").");
  }
}

//---------------------------------------------------------------------------

void mml::type_checker::do_variable_declaration_node(mml::variable_declaration_node * const node, int lvl) {
  
  bool initialized = false;
  bool function = node->is_typed(cdk::TYPE_FUNCTIONAL);
  bool forward = node->qualifier() == tFORWARD;
  bool is_auto = false;

  if (node->qualifier() == tFOREIGN) {
    function = true;
  }

  _parent->set_func_var_id(node->identifier());

  if (node->initializer() != nullptr) {

    if (node->qualifier() == tFOREIGN) {
      throw std::string("foreign variable must not have a initializer.");
    }

    if (forward) {
      throw std::string("forward variable must not have a initializer.");
    }

    initialized = true;

    node->initializer()->accept(this, lvl + 2);

    if (node->is_typed(cdk::TYPE_INT)) {
      if (!node->initializer()->is_typed(cdk::TYPE_INT)) {
        throw std::string("wrong type for initializer (integer expected).");
      }
    } else if (node->is_typed(cdk::TYPE_DOUBLE)) {
      if (!node->initializer()->is_typed(cdk::TYPE_INT) && !node->initializer()->is_typed(cdk::TYPE_DOUBLE)) {
        throw std::string("wrong type for initializer (integer or doubled expected).");
      }
    } else if (node->is_typed(cdk::TYPE_STRING)) {
      if (!node->initializer()->is_typed(cdk::TYPE_STRING)) {
        throw std::string("wrong type for initializer (string expected).");
      }
    } else if (node->is_typed(cdk::TYPE_VOID)) { 
      if (!node->initializer()->is_typed(cdk::TYPE_VOID)) {
        throw std::string("wrong type for initializer (void expected).");
      }
    } else if (node->is_typed(cdk::TYPE_POINTER)) {
      if (!node->initializer()->is_typed(cdk::TYPE_POINTER)) {
        throw std::string("wrong type for initializer (pointer expected).");
      }
    } else if (node->is_typed(cdk::TYPE_FUNCTIONAL)) {
      function = true;

      if (!node->initializer()->is_typed(cdk::TYPE_FUNCTIONAL)) {
        throw std::string("wrong type for initializer (function expected).");
      }
      std::shared_ptr<cdk::functional_type> node_type = std::static_pointer_cast<cdk::functional_type>(node->type());
      std::shared_ptr<cdk::functional_type> init_type = std::static_pointer_cast<cdk::functional_type>(node->initializer()->type());
      if (node_type->output()->component(0)->name() != init_type->output()->component(0)->name()) {
        throw std::string("mismatch of return type between function's variable and it's definition.");
      } else if (node_type->input()->length() != init_type->input()->length()) {
        throw std::string("mismatch of number of arguments between function's variable and it's definition.");
      }
      for (size_t i = 0; i < node_type->input()->length(); i++) {
        if (node_type->input()->component(i)->name() != node_type->input()->component(i)->name()) {
          throw std::string("mismatch of type of the " + std::to_string(i+1) + "th argument between function's variable and it's definition");
        }
      }
    } else if (node->is_typed(cdk::TYPE_UNSPEC)) {
      if (forward) {
        throw std::string("auto typed variable must not have 'forward' qualifier");
      }
      is_auto = true;
      if (node->initializer()->is_typed(cdk::TYPE_INT)) {
        node->type(cdk::primitive_type::create(4, cdk::TYPE_INT)); 
      } else if (node->initializer()->is_typed(cdk::TYPE_DOUBLE)) {
        node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
      } else if (node->initializer()->is_typed(cdk::TYPE_STRING)) {
        node->type(cdk::primitive_type::create(4, cdk::TYPE_STRING));
      } else if (node->initializer()->is_typed(cdk::TYPE_POINTER)) {
        node->type(cdk::primitive_type::create(4, cdk::TYPE_POINTER));
      } else if (node->initializer()->is_typed(cdk::TYPE_FUNCTIONAL)) {
        function = true;
        std::shared_ptr<cdk::functional_type> init_type = std::static_pointer_cast<cdk::functional_type>(node->initializer()->type());
        node->type(cdk::functional_type::create(init_type->input()->components(), init_type->output()->components()));
      }
    }
  }

  std::shared_ptr<mml::symbol> symbol;
  if (_parent->new_symbol() != nullptr) { // if function symbol was created
    symbol = mml::make_symbol(node->type(), node->identifier(), 0, node->constant(), node->qualifier(), initialized, function, forward, false, is_auto, _parent->new_symbol()->name());
  } else {
    std::string forward_func_id = "";
    if (forward) {
      forward_func_id = _parent->give_forward_func_id();
    }
    symbol = mml::make_symbol(node->type(), node->identifier(), 0, node->constant(), node->qualifier(), initialized, function, forward, false, is_auto, forward_func_id);
  }

  bool canInsert = true;
  auto previous = _symtab.find(node->identifier());
  if (previous != nullptr) {
    auto local_previous = _symtab.find_local(node->identifier());
    if (previous->forward()) {
      symbol->forward_done();
      if (_symtab.replace(node->identifier(), symbol)) {
        canInsert = false;
        _parent->set_new_symbol(symbol);
      } else {
        throw std::string("could not replace");
      }
    } else if (local_previous == nullptr) { // variable with the same name as another in a lower context
      canInsert = true; // useless, but readable
    } else {
      throw std::string("variable " + node->identifier() + " already declared in the same context");
    }
  }

  if (canInsert) {
    if (_symtab.insert(node->identifier(), symbol)) {
      _parent->set_new_symbol(symbol);
    } else {  
      throw std::string("could not insert");
    }
  }


}

//---------------------------------------------------------------------------

void mml::type_checker::do_sizeof_node(mml::sizeof_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->argument()->accept(this, lvl + 2);
  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}
