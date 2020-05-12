#ifndef LITERAL_H
#define LITERAL_H
#include "expression.h"

class Literal : public Expression {
private:
    std::shared_ptr<Value> _value;
public:
    Literal(Value *value) : _value(value), Expression() {}
    std::shared_ptr<Value> eval(Context *ctx) {
        return _value;
    }
};

#endif