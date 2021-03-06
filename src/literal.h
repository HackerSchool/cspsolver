#ifndef LITERAL_H
#define LITERAL_H
#include "expression.h"
#include "variableset.h"

class Literal : public Expression {
private:
    std::shared_ptr<Value> _value;
public:
    Literal(Value *value) : _value(value), Expression() {}
    std::shared_ptr<Value> eval(AssignmentSet *set) { return _value; }
    void check (VariableSet* set) { this->setType(_value->getType()); }
};

#endif