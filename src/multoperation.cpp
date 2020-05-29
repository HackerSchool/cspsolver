#include "multoperation.h"

std::shared_ptr<Value> MultOperation::eval(AssignmentSet *set) {

}

void MultOperation::check (AssignmentSet *set) {
    _left->check(set);
    _right->check(set);

    switch (_left->getType()->id()) {
        case Type::ID_INTEGER:
            
            break;
        
    }
}