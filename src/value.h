#ifndef VALUE_H
#define VALUE_H
#include <string>
#include <memory>
#include "type.h"

class Value {
public:
    Value() {}
    virtual Type* getType () = 0;
    virtual std::string toString () = 0;
    virtual std::shared_ptr<Value> add(std::shared_ptr<Value> right) = 0;
    virtual std::shared_ptr<Value> multiply(std::shared_ptr<Value> right) = 0;
};

#endif
