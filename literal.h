#ifndef LITERAL_H
#define LITERAL_H
#include "expression.h"

class Literal : public Expression {
private:
    Value *_value;
    std::list<int> _variables;
public:
    Literal(Value *value) : _value(value), Expression() {}
    Value *eval(Context *ctx) {
        return _value;
    }
    const std::list<int> &getVariables() { return _variables; }
};

#endif