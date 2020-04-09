#ifndef VARIABLES_DEFINITIONS_h
#define VARIABLES_DEFINITIONS_h
#include <vector>
#include "variabledefinition.h"

class VariablesDefinitions {
private:
    std::vector<VariableDefinition*> _vector;
public:
    VariablesDefinitions () {}
    void add (VariableDefinition* def) {_vector.push_back(def);}
};

#endif