#ifndef __MML_BASIC_AST_VISITOR_H__
#define __MML_BASIC_AST_VISITOR_H__

#include <string>
#include <memory>
#include <iostream>
#include <cdk/compiler.h>
#include <cdk/symbol_table.h>
#include "targets/symbol.h"

/* do not edit -- include node forward declarations */
#define __NODE_DECLARATIONS_ONLY__
#include ".auto/all_nodes.h"  // automatically generated
#undef __NODE_DECLARATIONS_ONLY__
/* do not edit -- end */

//!
//! Print nodes as XML elements to the output stream.
//!
class basic_ast_visitor {
protected:
  //! The owner compiler
  std::shared_ptr<cdk::compiler> _compiler;

private:

  // last symbol inserted in symbol table
  std::shared_ptr<mml::symbol> _new_symbol;
  std::shared_ptr<mml::symbol> _previous_new_symbol;

  int _func_id_giver = 0;

  bool _can_give_func_id = true;

  std::shared_ptr<mml::symbol> _last_func_symbol;

  std::string _func_var_id;

  std::shared_ptr<cdk::basic_type> _var_dec_type;

  bool _assignment_func_def = false;


protected:
  basic_ast_visitor(std::shared_ptr<cdk::compiler> compiler) :
      _compiler(compiler) {
  }

  bool debug() {
    return _compiler->debug();
  }

  std::ostream &os() {
    return *_compiler->ostream();
  }

public:
  virtual ~basic_ast_visitor() {
  }

public:

  bool assignment_func_def() {
    return _assignment_func_def;
  }

  void set_assignment_func_def(bool v) {
    _assignment_func_def = v;
  }


  std::shared_ptr<mml::symbol> new_symbol() {
    return _new_symbol;
  }
  std::shared_ptr<mml::symbol> previous_new_symbol() {
    return _previous_new_symbol;
  }
  void set_new_symbol(std::shared_ptr<mml::symbol> symbol) {
    _previous_new_symbol = _new_symbol;
    _new_symbol = symbol;
  }

  void set_last_func_symbol(std::shared_ptr<mml::symbol> symbol) {
    _last_func_symbol = symbol;
  }

  std::shared_ptr<mml::symbol> last_func_symbol() {
    return _last_func_symbol;
  }

  void reset_new_symbol() {
    _new_symbol = nullptr;
  }

  std::string give_main_func_id() {
    _can_give_func_id = false;
    return "_main";
  }

  std::string give_func_id() {
    _can_give_func_id = false;
    return "_func" + std::to_string(_func_id_giver++);
  }

  std::string give_forward_func_id() {
    return "_func" + std::to_string(_func_id_giver++);
  }

  std::string const current_func_id() const {
    int cur = _func_id_giver - 1;
    return "_func" + std::to_string(cur);
  }

  bool can_give_func_id() {
    return _can_give_func_id;
  }

  void allow_func_id_giving() {
    _can_give_func_id = true;
  }

  void disallow_func_id_giving() {
    _can_give_func_id = false;
  }

  void set_func_var_id(const std::string &s) {
    _func_var_id = s;
  }

  std::string const func_var_id() const {
    return _func_var_id;
  }

  void set_var_dec_type(std::shared_ptr<cdk::basic_type> t) {
    _var_dec_type = t;
  }

  std::shared_ptr<cdk::basic_type> var_dec_type() {
    return _var_dec_type;
  }

public:
  // do not edit these lines
#define __IN_VISITOR_HEADER__
#define __PURE_VIRTUAL_DECLARATIONS_ONLY__
#include ".auto/visitor_decls.h"       // automatically generated
#undef __PURE_VIRTUAL_DECLARATIONS_ONLY__
#undef __IN_VISITOR_HEADER__
  // do not edit these lines: end

};

#endif
