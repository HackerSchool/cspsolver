#ifndef VARIABLE_IDENTIFIER_H
#define VARIABLE_IDENTIFIER_H
#include "expression.h"

class VariableIdentifier : public Expression {
private:
    int _id;
public:
    VariableIdentifier(int id) : _id(id), Expression() {
        _variables.insert(_id);
    }
    std::shared_ptr<Value> eval(AssignmentSet *set) {
        if (set->assigned(_id))
            return set->value(_id);
        else
            throw "Error: Variable is not assigned";
    }
};

#endif