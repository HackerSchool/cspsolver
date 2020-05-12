#include "integervalue.h"

std::string IntegerValue::toString () {
    return std::to_string(_val);
}

std::shared_ptr<Value> IntegerValue::add(std::shared_ptr<Value> right) {
    if (right->getType()->equals(&Type::INTEGER)) {
        // bottleneck?
        std::shared_ptr<IntegerValue> integer = std::dynamic_pointer_cast<IntegerValue> (right);
        return std::make_shared<IntegerValue>(_val + integer->_val);
    } else {
        throw "IntegerValue::add: incorrect type";
    }
    
}

std::shared_ptr<Value> IntegerValue::multiply(std::shared_ptr<Value> right) {
    if (right->getType()->equals(&Type::INTEGER)) {
        // bottleneck?
        std::shared_ptr<IntegerValue> integer = std::dynamic_pointer_cast<IntegerValue> (right);
        return std::make_shared<IntegerValue> (_val + integer->_val);
    } else {
        throw "IntegerValue::multiply: incorrect type";
    }
    
}