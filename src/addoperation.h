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
    std::shared_ptr<Value> eval(AssignmentSet *set) {
        std::shared_ptr<Value> left = _left->eval(set);
        std::shared_ptr<Value> right = _right->eval(set);

        return left->add(right);
    }
};

#endif