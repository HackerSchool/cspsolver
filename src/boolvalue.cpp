#include "boolvalue.h"

std::string BoolValue::toString () {
    return std::to_string(_val);
}

Value* BoolValue::add(Value* right) {
    throw "BOOL: add not supported";
};