#include "ltoperation.h"
#include "integervalue.h"
#include "errormessage.h"

std::shared_ptr<Value> LtOperation::eval(AssignmentSet *set) {
    auto l = std::dynamic_pointer_cast<IntegerValue>(_left->eval(set));
    auto r = std::dynamic_pointer_cast<IntegerValue>(_right->eval(set));

    return std::make_shared<IntegerValue> (l->value() < r->value());
}

void LtOperation::check (AssignmentSet *set) {
    _left->check(set);
    _right->check(set);

    if (_left->getType()->id() != Type::ID_INTEGER || 
        _right->getType()->id() != Type::ID_INTEGER)
        throw EM_MULT_WRONG_TYPES;
}