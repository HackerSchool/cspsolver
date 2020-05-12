#ifndef VARIABLE_H
#define VARIABLE_H
#include <string>
#include "expression.h"
#include "setvalue.h"

class Variable {
private:
    Expression* _domainExp;
    SetValue* _domain;
    Type* _type;
    std::string _name;
    int _id;
public:
    Variable (Expression* domainExp, Type* type, const std::string & name) :
        _domainExp(domainExp), _type(type), _domain(nullptr), _name(name) {}
    
    // FIXME really need Context? And if variable identifier pointed to this?
    std::shared_ptr<Value> value (Context* ctx) {return ctx->value(_id);}
    void assign (Context* ctx, std::shared_ptr<Value> value) {ctx->assign(_id, value);}
    bool assigned (Context* ctx) {return ctx->assigned(_id);}
    
    void setId (int id) {_id = id;}
    const std::string& name () {return _name;}
};

#endif
