#include "variableset.h"

int VariableSet::searchId (const std::string& name) {
    for (int i = 0; i < _vector.size(); i++) {
        Variable* var = _vector.at(i);
        if(var->name() == name)
            return i;
    }

    throw "Error: not found";
}

void VariableSet::add (Variable* var) {
    var->setId(_nextId++); 
    _vector.push_back(var);
}

Variable* VariableSet::get (int id) {
    if (id >= _vector.size() || id < 0)
        throw "Error: variable not found: invalid id";

    return _vector[id];
}