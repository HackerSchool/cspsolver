#include "constraintset.h"

bool ConstraintSet::allTrue (AssignmentSet* set) {
    for (Constraint* constraint: _vector)
        if (constraint->eval(set) == false)
            return false;
    
    return true;
}