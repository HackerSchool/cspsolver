#ifndef PROBLEM_H
#define PROBLEM_H
#include <vector>
#include "variableset.h"
#include "constraintset.h"

class Problem {
private:
    // problem variables
    VariableSet _variableSet;
    // problem constraints
    ConstraintSet _constraintSet;
public:
    Problem() {}
    void addVariable (Variable* var) {_variableSet.add(var);}
    void addConstraint (Constraint* ctr) {_constraintSet.add(ctr);}
    int searchVariableId (const std::string& name);
    void solve ();

private:
    bool recursiveSolve (AssignmentSet* set);
};

#endif
