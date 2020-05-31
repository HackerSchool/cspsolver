#ifndef SET_VALUE_H
#define SET_VALUE_H

#include "value.h"
#include "type.h"
#include <vector>

class SetValue : public Value {
private:
    std::vector<std::shared_ptr<Value>> _values;
public:
    SetValue(const std::vector<std::shared_ptr<Value>>& values) : _values(values) {}
    SetValue() {}
    Type* getType () {return &Type::SET;}
    std::string toString ();

    std::shared_ptr<Value> get(int i);
    size_t size () { return _values.size(); }
};

#endif
