#ifndef VARIABLES_SET_H
#define VARIABLES_SET_H
#include <vector>
#include "variable.h"

class VariableSet {
private:
    int _nextId;
    std::vector<Variable*> _vector;
public:
    VariableSet () : _nextId(0) {}
    int searchId (const std::string& name);
    void add (Variable* var);
};

#endif