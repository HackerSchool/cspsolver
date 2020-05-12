#include "boolvalue.h"

std::string BoolValue::toString () {
    return std::to_string(_val);
}

std::shared_ptr<Value> BoolValue::add(std::shared_ptr<Value> right) {
    throw "BOOL: add not supported";
}

std::shared_ptr<Value> BoolValue::multiply(std::shared_ptr<Value> right) {
    throw "BOOL: multiply not supported";
}
