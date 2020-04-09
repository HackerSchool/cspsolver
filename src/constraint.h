#ifndef CONSTRAINT_H
#define CONSTRAINT_H

#include "expression.h"

class Constraint {
private:
    Expression *_exp;
public:
    Constraint(Expression* exp) : _exp(exp) {}
    bool eval (Context* ctx) {return false;}
};

#endif