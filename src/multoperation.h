#ifndef MULTOPERATION_H
#define MULTOPERATION_H
#include "expression.h"

class MultOperation : public Expression {
private:
    Expression *_left, *_right;
public:
    MultOperation(Expression *left, Expression *right) : _left(left), _right(right), Expression() {
        std::set<int> left_vars = left->getVariables();
        std::set<int> right_vars = right->getVariables();
        std::set_union(left_vars.begin(), left_vars.end(),
                       right_vars.begin(), right_vars.end(),
                       std::inserter(_variables, _variables.begin()));
    }
    Value *eval(Context *ctx) {
        Value* left = _left->eval(ctx);
        Value* right = _right->eval(ctx);

        return left->multiply(right);
    }
};

#endif