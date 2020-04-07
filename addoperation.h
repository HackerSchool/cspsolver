#ifndef ADDOPERATION_H
#define ADDOPERATION_H
#include "expression.h"

class AddOperation : public Expression {
private:
    Expression *_left, *_right;
public:
    AddOperation(Expression *left, Expression *right) : _left(left), _right(right), Expression() {
        std::set<int> left_vars = left->getVariables();
        std::set<int> right_vars = right->getVariables();
        std::set_union(left_vars.begin(), left_vars.end(),
                       right_vars.begin(), right_vars.end(),
                       std::inserter(_variables, _variables.begin()));
    }
    Value *eval(Context *ctx) {
        return (_left->eval(ctx))->add(_right->eval(ctx));
    }
};

#endif