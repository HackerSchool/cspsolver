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
    std::shared_ptr<Value> add(std::shared_ptr<Value> right);
    std::shared_ptr<Value> multiply(std::shared_ptr<Value> right);
};

#endif
