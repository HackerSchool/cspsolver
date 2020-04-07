#ifndef ADDOPERATION_H
#define ADDOPERATION_H
#include "expression.h"

class AddOperation : public Expression {
private:
    Expression *_left, *_right;
    std::list<int> _variables;
public:
    AddOperation(Expression *left, Expression *right) : _left(left), _right(right), Expression() {
        _variables = left->getVariables();
        std::list<int> right_vars = right->getVariables();

        // TODO - Merge right_vars to _variables
    }

};

#endif