#ifndef __MML_TARGETS_SYMBOL_H__
#define __MML_TARGETS_SYMBOL_H__

#include <string>
#include <memory>
#include <cdk/types/basic_type.h>

namespace mml {

  class symbol {
    std::shared_ptr<cdk::basic_type> _type; // type (type id + type size)
    std::string _name = "";
    long _value; // hack!


    bool _constant; // is it a constant?
    int _qualifier; // qualifiers: public, forward, "private" (i.e., none)
    std::vector<std::shared_ptr<cdk::basic_type>> _argument_types;
    bool _initialized; // initialized?
    int _offset = 0; // 0 (zero) means global variable/function
    bool _function; // false for variables
    bool _forward = false;
    bool _forward_done;
    bool _is_auto;
    std::string _referenced_func_id;

    std::string _body_ret_label;

  public:
    symbol(std::shared_ptr<cdk::basic_type> type, const std::string &name, long value,
           bool constant = false, int qualifier = 0, bool initialized = false,
           bool function = false, bool forward = false, bool forward_done = false, bool is_auto = false,
           const std::string &referenced_func_id = "") :
        _type(type), _name(name), _value(value),
        _constant(constant), _qualifier(qualifier), _initialized(initialized), 
        _function(function), _forward(forward), _forward_done(forward_done), _is_auto(is_auto),
        _referenced_func_id(referenced_func_id) {
    }

    virtual ~symbol() {
      // EMPTY
    }

     std::string body_ret_label() {
      return _body_ret_label;
    }

    void set_body_ret_label(std::string s) {
      _body_ret_label = s;
    }

    std::shared_ptr<cdk::basic_type> type() const {
      return _type;
    }
    bool is_typed(cdk::typename_type name) const {
      return _type->name() == name;
    }   
    void set_type(std::shared_ptr<cdk::basic_type> t) {
      _type = t;
    }

    const std::string &name() const {
      return _name;
    }
    const std::string& referenced_func_id() const {
      return _referenced_func_id;
    }
    long value() const {
      return _value;
    }
    long value(long v) {
      return _value = v;
    }
    bool constant() const {
      return _constant;
    }
    int qualifier() const {
      return _qualifier;
    }
    const std::string& identifier() const {
      return name();
    }
    bool initialized() const {
      return _initialized;
    }
    int offset() const {
      return _offset;
    }
    void set_offset(int offset) {
      _offset = offset;
    }
    bool isFunction() const {
      return _function;
    }

    bool global() const {
      return _offset == 0;
    }
    bool isVariable() const {
      return !_function;
    }

    bool forward() const {
      return _forward;
    }

    void forward_done() {
      _forward_done = true;
    }

    bool forward_is_done() {
      return _forward_done;
    }

    void set_argument_types(const std::vector<std::shared_ptr<cdk::basic_type>> &types) {
      _argument_types = types;
    }

    bool argument_is_typed(size_t ax, cdk::typename_type name) const {
      return _argument_types[ax]->name() == name;
    }
    std::shared_ptr<cdk::basic_type> argument_type(size_t ax) const {
      return _argument_types[ax];
    }

    size_t argument_size(size_t ax) const {
      return _argument_types[ax]->size();
    }

    size_t number_of_arguments() const {
      return _argument_types.size();
    }

    void set_referenced_func_id(std::string s) {
      _referenced_func_id = s;
    }
  };

  inline auto make_symbol(std::shared_ptr<cdk::basic_type> type, const std::string &name, long value,
                          bool constant = false, int qualifier = 0, bool initialized = false,
                          bool function = false, bool forward = false, bool forward_done = false, bool is_auto = false,
                          const std::string &referenced_func_id = "") {
    return std::make_shared<symbol>(type, name, value, constant, qualifier, initialized, function, forward, forward_done, is_auto, referenced_func_id);
  }

} // mml

#endif