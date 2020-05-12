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
    std::shared_ptr<Value> add(std::shared_ptr<Value> right);
    std::shared_ptr<Value> multiply(std::shared_ptr<Value> right);
};

#endif
