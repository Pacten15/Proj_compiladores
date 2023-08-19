#ifndef __MML_TARGETS_TYPE_CHECKER_H__
#define __MML_TARGETS_TYPE_CHECKER_H__

#include "targets/basic_ast_visitor.h"

namespace mml {

  /**
   * Print nodes as XML elements to the output stream.
   */
  class type_checker: public basic_ast_visitor {
    cdk::symbol_table<mml::symbol> &_symtab;
    std::shared_ptr<mml::symbol> _function;
    basic_ast_visitor *_parent;
    std::shared_ptr<cdk::basic_type> _inBlockReturnType = nullptr;

  public:
    type_checker(std::shared_ptr<cdk::compiler> compiler, cdk::symbol_table<mml::symbol> &symtab,  std::shared_ptr<mml::symbol> func, basic_ast_visitor *parent) :
        basic_ast_visitor(compiler), _symtab(symtab), _function(func), _parent(parent) {
    }

  public:
    ~type_checker() {
      os().flush();
    }

  protected:

    void processIDExpression(cdk::binary_operation_node * const node, int lvl);
    void processPIDExpression(cdk::binary_operation_node * const node, int lvl);
    void processScalarLogicalExpression(cdk::binary_operation_node * const node, int lvl);
    void processBooleanLogicalExpression(cdk::binary_operation_node * const node, int lvl);
    void processGeneralLogicalExpression(cdk::binary_operation_node * const node, int lvl);
    void processIntOnlyExpression(cdk::binary_operation_node * const node, int lvl);

    void processUnaryExpression(cdk::unary_operation_node *const node, int lvl);
    template<typename T>
    void process_literal(cdk::literal_node<T> *const node, int lvl) {
    }

  public:
    // do not edit these lines
#define __IN_VISITOR_HEADER__
#include ".auto/visitor_decls.h"       // automatically generated
#undef __IN_VISITOR_HEADER__
    // do not edit these lines: end

  };



//---------------------------------------------------------------------------
//     HELPER MACRO FOR TYPE CHECKING
//---------------------------------------------------------------------------

  #define CHECK_TYPES(compiler, symtab, function, node) { \
    try { \
      mml::type_checker checker(compiler, symtab, function, this); \
      (node)->accept(&checker, 0); \
    } \
    catch (const std::string &problem) { \
      std::cerr << (node)->lineno() << ": " << problem << std::endl; \
      return; \
    } \
  }

  #define ASSERT_SAFE_EXPRESSIONS CHECK_TYPES(_compiler, _symtab, _function, node)

} // mml

#endif
