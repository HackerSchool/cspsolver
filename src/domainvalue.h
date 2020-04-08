#ifndef DOMAIN_VALUE_H
#define DOMAIN_VALUE_h

#include "value.h"

class DomainValue : public Value {
private:
public:
    DomainValue() {}
    Type* getType () {return &Type::DOMAIN;}
    std::string toString ();
    Value* add(Value* right);
};

#endif