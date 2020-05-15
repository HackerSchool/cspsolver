#include "problem.h"
#include "assignmentset.h"

int Problem::searchVariableId (const std::string& name) {
    return _variableSet.searchId (name); 
}

void Problem::solve () {
    AssignmentSet assignmentSet(_variableSet.count());

    //solve by recursive backtracking
    recursiveSolve(&assignmentSet);
}

bool Problem::recursiveSolve (AssignmentSet* set) {
    if (set->isCompleteAssignment())
        return true;
    
    // select unassigned variable
    int varId = set->selectUnassigned();
    Variable* variable = _variableSet.get(varId);

    // try each one of this values
    for (size_t i = 0; i < variable->domainSize(); i++) {
        // try this one
        set->assign(varId, variable->getDomainValue(i));

        if (_constraintSet.allTrue(set))
            if (recursiveSolve(set) == true)
                return true;

        set->unassign(varId);
    }

    // if no value satisfies
    return false;
}