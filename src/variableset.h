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
    Variable* getById (int id);

    // returns the (1st) variable with the name, or null if not found
    Variable* getByName (const std::string& name);

    // checks types
    void check ();
};

#endif
