#ifndef BOOL_VALUE_H
#define BOOL_VALUE_H
#include <string>
#include "value.h"

class BoolValue : public Value {
private:
    bool _val;
public:
    BoolValue(bool val) : _val(val) {}
    Type* getType () {return &Type::BOOL;}
    std::string toString () { return std::to_string(_val); }
    bool value () { return _val; }
};

#endif