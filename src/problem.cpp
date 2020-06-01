#include "problem.h"
#include "assignmentset.h"
#include "errormessage.h"

/* FIXME need?*/
#include <iostream>

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
    if (recursiveSolve(&assignmentSet)) {
        std::cout << assignmentSet.toString(_variableSet) << std::endl;
    } else {
        std::cout << "No solution" << std::endl;
    }
}

bool Problem::recursiveSolve (AssignmentSet* set) {
    if (set->isCompleteAssignment())
        return true;
    
    // select unassigned variable
    int varId = set->selectUnassigned();
    Variable* variable = _variableSet->getById(varId);

    // try each one of this values
    auto domain = variable->evalDomain();

    for (size_t i = 0; i < domain->size(); i++) {
        // try this one
        set->assign(varId, domain->get(i));

        if (_constraintSet->allTrue(set))
            if (recursiveSolve(set) == true)
                return true;

        set->unassign(varId);
    }

    // if no value satisfies
    return false;
}

void Problem::check () {
    _variableSet->check();
    _constraintSet->check(_variableSet);
}