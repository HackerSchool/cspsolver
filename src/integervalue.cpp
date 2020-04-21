#include "integervalue.h"

std::string IntegerValue::toString () {
    return std::to_string(_val);
}

Value* IntegerValue::add(Value* right) {
    if (right->getType()->equals(&Type::INTEGER)) {
        // bottleneck?
        IntegerValue* integer = dynamic_cast<IntegerValue*> (right);
        return new IntegerValue(_val + integer->_val);
    } else {
        throw "IntegerValue::add: incorrect type";
    }
    
}

Value* IntegerValue::multiply(Value* right) {
    if (right->getType()->equals(&Type::INTEGER)) {
        // bottleneck?
        IntegerValue* integer = dynamic_cast<IntegerValue*> (right);
        return new IntegerValue(_val + integer->_val);
    } else {
        throw "IntegerValue::multiply: incorrect type";
    }
    
}