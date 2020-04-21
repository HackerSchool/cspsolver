#ifndef INTEGER_VALUE_H
#define INTEGER_VALUE_H
#include <string>

#include "value.h"

class IntegerValue : public Value {
private:
    int _val;
public:
    IntegerValue(int val) : _val(val) {}
    Type* getType () {return &Type::INTEGER;}
    std::string toString ();
    Value* add(Value* right);
    Value* multiply(Value* right);
};

#endif
