#ifndef SET_VALUE_H
#define SET_VALUE_H

#include "value.h"
#include "type.h"

class SetValue : public Value {
private:
public:
    SetValue() {}
    Type* getType () {return &Type::SET;}
    std::string toString ();

    std::shared_ptr<Value> get(int id);
    size_t size () { /* FIXME */ }
};

#endif
