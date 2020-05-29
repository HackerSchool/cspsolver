#include "ltoperation.h"

std::shared_ptr<Value> LtOperation::eval(AssignmentSet *set) {
    std::shared_ptr<Value> left = _left->eval(set);
    std::shared_ptr<Value> right = _right->eval(set);
}

void LtOperation::check(AssignmentSet *set) {
    
}