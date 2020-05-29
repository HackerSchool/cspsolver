#include "problem.h"
#include "assignmentset.h"
#include "errormessage.h"

Problem::Problem(const std::string name, VariableSet* variables, ConstraintSet* constraints) :
     _name(name), _variableSet(variables), _constraintSet(constraints) {
    
    // check arguments
    if (!variables) throw EM_PROBLEM_VARSET_NULL;
    if (!constraints) throw EM_PROBLEM_CONSET_NULL;
}

int Problem::searchVariableId (const std::string& name) {
    return _variableSet->searchId (name); 
}

void Problem::solve () {
    AssignmentSet assignmentSet(_variableSet->count());

    //solve by recursive backtracking
    recursiveSolve(&assignmentSet);
}

bool Problem::recursiveSolve (AssignmentSet* set) {
    if (set->isCompleteAssignment())
        return true;
    
    // select unassigned variable
    int varId = set->selectUnassigned();
    Variable* variable = _variableSet->get(varId);

    // try each one of this values
    for (size_t i = 0; i < variable->domainSize(); i++) {
        // try this one
        set->assign(varId, variable->getDomainValue(i));

        if (_constraintSet->allTrue(set))
            if (recursiveSolve(set) == true)
                return true;

        set->unassign(varId);
    }

    // if no value satisfies
    return false;
}