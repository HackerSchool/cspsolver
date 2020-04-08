#ifndef LITERAL_H
#define LITERAL_H
#include "expression.h"

class Literal : public Expression {
private:
    Value *_value;
public:
    Literal(Value *value) : _value(value), Expression() {}
    Value *eval(Context *ctx) {
        return _value;
    }
};

#endif