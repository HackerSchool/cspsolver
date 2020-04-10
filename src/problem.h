#ifndef PROBLEM_H
#define PROBLEM_H
#include <vector>
#include "variableset.h"
#include "constraintset.h"

class Problem {
private:
    VariableSet _variables;
    ConstraintSet _constraints;
public:
    Problem() {}
    void addVariable (Variable* var) {_variables.add(var);}
    void addConstraint (Constraint* ctr) {_constraints.add(ctr);}
    int searchVariableId (const std::string& name);
    void solve ();
};

#endif
