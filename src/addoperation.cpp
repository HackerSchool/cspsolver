#include "addoperation.h"

std::shared_ptr<Value> AddOperation::eval(AssignmentSet *set) {
    std::shared_ptr<Value> left = _left->eval(set);
    std::shared_ptr<Value> right = _right->eval(set);
}

void AddOperation::check(AssignmentSet *set) {
    
}