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
    
    void setId (int id) {_id = id;}
    const std::string& name () {return _name;}

    size_t domainSize () { return _domain->size(); }
    std::shared_ptr<Value> getDomainValue (size_t i) { return _domain->get(i); }

    int getId() { return _id; }
};

#endif
