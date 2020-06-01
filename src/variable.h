#ifndef VARIABLE_H
#define VARIABLE_H
#include <string>
#include "expression.h"
#include "setvalue.h"

class Variable {
private:
    Expression* _domainExp;
    Type* _type;
    std::string _name;
    int _id;
public:
    Variable (Expression* domainExp, Type* type, const std::string & name) :
        _domainExp(domainExp), _type(type), _name(name) {}
    
    void setId (int id) {_id = id;}
    const std::string& name () {return _name;}

    std::shared_ptr<SetValue> evalDomain ();
    void check ();

    int getId() { return _id; }
    Type* getType() { return _type; }
};

#endif
