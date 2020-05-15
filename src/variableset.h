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

    // returns the id of the varible with the given name
    int searchId (const std::string& name);
    
    // sets the id of var and adds the variable to the set
    void add (Variable* var);

    // get the number of variables stored
    int count () { return _vector.size(); }

    // returns the variable with the specified id
    Variable* get (int id);
};

#endif
