#include "assignmentset.h"
#include "variableset.h"

AssignmentSet::AssignmentSet(int count) : _assignedCount(0), _values(count) {
    
}

bool AssignmentSet::assigned(int id) {
    checkId(id);
    return _values.at(id) != nullptr;
}

std::shared_ptr<Value> AssignmentSet::value(int id) {
    checkId(id);
    return _values.at(id);
}

bool AssignmentSet::isCompleteAssignment () {
    return _assignedCount == _values.size();
}


void AssignmentSet::sortVariables () {

}

int AssignmentSet::selectUnassigned () {
    if (_assignedCount == _values.size())
        throw "not available variables to assign";

    // find the first variable that is not assigned
    for (size_t i = 0; i < _values.size(); i++)
        if (_values.at(i) == nullptr)
            return i;
    
    throw "not available variables to assign";
}

void AssignmentSet::assign (int var, std::shared_ptr<Value> value) { 
    checkId(var);

    // check if is not already assigned, to count assigned variables
    if (_values.at(var) == nullptr)
        _assignedCount ++;

    _values[var] = value;
}

void AssignmentSet::unassign (int var) {
    checkId(var);

    if (_values.at(var) == nullptr)
        throw "unassign unassigned variable";

    _values[var] = nullptr;

    //decrement assigned variables
    _assignedCount --;
}

void AssignmentSet::checkId (int id) {
    if (id >= _values.size() || id < 0)
        throw "variable not found: invalid id";
}

std::string AssignmentSet::toString (VariableSet* set) {
    std::string ret = "{";

    for (size_t i = 0; i < _values.size(); i++) {
        ret += set->getById(i)->name() + " = " + _values.at(i)->toString();
        
        if (i != _values.size() - 1)
            ret += ", ";
    }

    return ret + "}";
}