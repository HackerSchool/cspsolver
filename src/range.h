#ifndef RANGE_H
#define RANGE_H
#include "expression.h"
#include "setvalue.h"

class Range : public Expression {
    Expression *_begin, *_end, *_step;
public:
    Range(Expression* begin, Expression* end, Expression* step = nullptr);
    std::shared_ptr<Value> eval(AssignmentSet *set);
    void check (VariableSet *set);
};

#endif