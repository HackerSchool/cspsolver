#ifndef SET_VALUE_H
#define SET_VALUE_h

#include "value.h"
#include "type.h"

class SetValue : public Value {
private:
public:
    SetValue() {}
    Type* getType () {return &Type::SET;}
    std::string toString ();
    Value* add(Value* right);
    Value* multiply(Value* right);
};

#endif
