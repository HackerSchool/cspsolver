#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <set>
#include <algorithm>
#include "value.h"

class AssignmentSet;
class VariableSet;

class Type;

class Expression {
private:
    Type *_type;
protected:
    std::set<int> _variables;
public:
    Expression(Type *type = nullptr) : _type(type) {}
    void setType(Type *type) { _type = type; }
    Type *getType() { return _type; }
    const std::set<int> &getVariables() { return _variables; }

    virtual std::shared_ptr<Value> eval(AssignmentSet *set) = 0;
    virtual void check(VariableSet* set) = 0;
};

#endif