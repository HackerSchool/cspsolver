#include "variableset.h"
#include "errormessage.h"
#include <exception>

int VariableSet::searchId (const std::string& name) {
    for (int i = 0; i < _vector.size(); i++) {
        Variable* var = _vector.at(i);
        if(var->name() == name)
            return i;
    }

    throw EM_ID_NOT_FOUND;
}

void VariableSet::add (Variable* var) {
    var->setId(_nextId++); 
    _vector.push_back(var);
}

Variable* VariableSet::getById (int id) {
    if (id >= _vector.size() || id < 0)
        throw EM_ID_OUT_OF_BOUNDS;

    return _vector[id];
}

Variable* VariableSet::getByName (const std::string& name) {
    for (Variable* var: _vector) {
        if (var->name() == name)
            return var;
    }

    return nullptr;
}

void VariableSet::check () {
    for (Variable* var : _vector)
        var->checkDomain(); // FIXME verifcar se é duplicado
}