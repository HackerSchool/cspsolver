#include "setvalue.h"
#include "errormessage.h"

std::string SetValue::toString () {
    std::string ret = "{";

    for (size_t i = 0; i < _values.size(); i++) {
        ret += _values.at(i)->toString();
        
        if (i != _values.size() - 1)
            ret += ", ";
    }

    return ret + "}";
}

std::shared_ptr<Value> SetValue::get(int id) {
    if (id < 0 || id >_values.size())
        throw EM_ID_OUT_OF_BOUNDS;

    return _values.at(id);
}