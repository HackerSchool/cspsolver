#ifndef VARIABLE_IDENTIFIER_H
#define VARIABLE_IDENTIFIER_H
#include "expression.h"
#include "errormessage.h"
#include <string>

class VariableIdentifier : public Expression {
private:
    int _id;
    std::string _name;
public:
    VariableIdentifier(const std::string& name) : _name(name), Expression(), _id(-1) {
        _variables.insert(_id);
    }

    void setId (int id) { _id = id; }

    std::shared_ptr<Value> eval(AssignmentSet *set);
    void check (AssignmentSet *set);
};

#endif