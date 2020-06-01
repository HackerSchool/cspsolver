#ifndef LEOPERATION_H
#define LEOPERATION_H
#include "expression.h"

class VariableSet;

class LeOperation : public Expression {
private:
    Expression *_left, *_right;
public:
    LeOperation(Expression *left, Expression *right) : _left(left), _right(right), Expression() {
        std::set<int> left_vars = left->getVariables();
        std::set<int> right_vars = right->getVariables();
        std::set_union(left_vars.begin(), left_vars.end(),
                       right_vars.begin(), right_vars.end(),
                       std::inserter(_variables, _variables.begin()));
    }
    std::shared_ptr<Value> eval(AssignmentSet *set);
    void check(VariableSet* set);
};

#endif