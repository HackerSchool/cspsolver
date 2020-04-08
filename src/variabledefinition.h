#ifndef VARIABLE_DEFINITION_H
#define VARIABLE_DEFINITION_H

#include "expression.h"
#include "domainvalue.h"

class VariableDefinition {
private:
    Expression* _domainExp;
    DomainValue* _domain;
    Type* _type;
    int _id;
public:
    VariableDefinition (Expression* domainExp, Type* type, int id) :
        _domainExp(domainExp), _type(type), _id(id), _domain(nullptr) {}
    
    // really need Context? And if variable identifier pointed to this?
    Value* value (Context* ctx) {return ctx->value(_id);}
    void assign (Context* ctx, Value* value) {ctx->assign(_id, value);}
    bool assigned (Context* ctx) {return ctx->assigned(_id);}
};

#endif