#include "constraintset.h"

bool ConstraintSet::allTrue (AssignmentSet* set) {
    for (Constraint* constraint: _vector)
        if (constraint->eval(set) == false)
            return false;
    
    return true;
}

void ConstraintSet::check (VariableSet* set) {
    for (Constraint* constraint : _vector)
        constraint->check(set);
}