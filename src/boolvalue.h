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
    std::string toString ();
    Value* add(Value* right);
    Value* multiply(Value* right);
};

#endif