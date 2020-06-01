#include "constraint.h"
#include "boolvalue.h"
#include "unassignedvariable.h"

bool Constraint::eval (AssignmentSet* set) {
    std::shared_ptr<Value> value;
    
    try {
        value = _exp->eval(set); 
    } catch (UnassignedVariable&) {
        return true; // FIXME if allow and, or... probably, or, and will 
        //catch it first and handle
    }
    auto boolvalue = std::dynamic_pointer_cast<BoolValue> (value);

    return boolvalue->value();
}

void Constraint::check (VariableSet* set) {
    _exp->check(set);
}