#include "addoperation.h"
#include "errormessage.h"
#include "integervalue.h"

std::shared_ptr<Value> AddOperation::eval(AssignmentSet *set) {
    auto l = std::dynamic_pointer_cast<IntegerValue>(_left->eval(set));
    auto r = std::dynamic_pointer_cast<IntegerValue>(_right->eval(set));

    return std::make_shared<IntegerValue> (l->value() + r->value());
}

void AddOperation::check(VariableSet* set) {
    _left->check(set);
    _right->check(set);

    if (_left->getType()->id() != Type::ID_INTEGER || 
        _right->getType()->id() != Type::ID_INTEGER)
        throw EM_MULT_WRONG_TYPES;

    setType(&Type::INTEGER);
}