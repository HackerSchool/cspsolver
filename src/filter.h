#ifndef FILTER_H
#define FILTER_H
#include "expression.h"
#include "setvalue.h"

class Filter : public Expression {
    Expression *_exp, *_set, *_cond;
    std::string _id;
public:
    Filter(Expression* exp, const std::string& id, 
        Expression* set, Expression* cond = nullptr);
    std::shared_ptr<Value> eval(AssignmentSet *set);
    void check (VariableSet *set);
};

#endif