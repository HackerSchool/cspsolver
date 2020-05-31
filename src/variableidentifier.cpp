#include "variableidentifier.h"
#include "assignmentset.h"
#include "variableset.h"
#include "errormessage.h"
#include "unassignedvariable.h"

std::shared_ptr<Value> VariableIdentifier::eval(AssignmentSet *set) {
    if (_id == -1) 
        throw EM_VARID_ID_NOT_SETTED;

    if (set->assigned(_id))
        return set->value(_id);
    else
        throw UnassignedVariable();
}

void VariableIdentifier::check (VariableSet* set) {
    Variable* variable = set->getByName(_name);

    if (variable == nullptr)
        throw EM_VARIABLE_NAME_NOT_FOUND;

    _id = variable->getId();
    setType(variable->getType());
}