#ifndef VALUE_H
#define VALUE_H
#include "type.h"

class Value {
private:
    Type* _type;
public:
    Value(Type* type) : _type(type) {}
    Type* getType () {return _type;}    
};

#endif
