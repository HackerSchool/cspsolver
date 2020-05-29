#include "variableidentifier.h"

std::shared_ptr<Value> VariableIdentifier::eval(AssignmentSet *set) {
    if (_id == -1) 
        throw EM_VARID_ID_NOT_SETTED;

    if (set->assigned(_id))
        return set->value(_id);
    else
        throw "Error: Variable is not assigned";
}

void VariableIdentifier::check (AssignmentSet *set) {
    
}