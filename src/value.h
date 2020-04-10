#ifndef VALUE_H
#define VALUE_H
#include <string>
#include "type.h"

class Value {
public:
    Value() {}
    virtual Type* getType () = 0;
    virtual std::string toString () = 0;
    virtual Value* add(Value* right) = 0;
};

#endif
