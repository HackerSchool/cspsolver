#include "constraint.h"
#include "boolvalue.h"

bool Constraint::eval (AssignmentSet* set) {
    auto value = _exp->eval(set);
    auto boolvalue = std::dynamic_pointer_cast<BoolValue> (value);

    return boolvalue->value();
}

void Constraint::check (VariableSet* set) {
    _exp->check(set);
}