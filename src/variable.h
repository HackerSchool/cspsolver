#ifndef VARIABLE_H
#define VARIABLE_H
#include "expression.h"

class Variable : public Expression {
private:
    int _id;
public:
    Variable(int id) : _id(id), Expression() {
        _variables.insert(_id);
    }
    Value *eval(Context *ctx) {
        if (ctx->assigned(_id))
            return ctx->value(_id);
        else
            throw "Error: Variable is not assigned";
    }
};

#endif