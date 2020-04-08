#ifndef PROBLEM_H
#define PROBLEM_H
#include <vector>
#include "variabledefinition.h"
#include "context.h"

class Constraint;

class Problem {
private:
    std::vector<VariableDefinition*> _variableDefs;
    std::vector<Constraint*> _constraints;
    Context _context;
public:
    Problem() {}
    void solve ();
};

#endif