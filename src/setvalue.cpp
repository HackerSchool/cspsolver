#include "setvalue.h"
#include "errormessage.h"

std::string SetValue::toString () {
    return "TODO: DEFINE";
}

std::shared_ptr<Value> SetValue::get(int id) {
    if (id < 0 || id >_values.size())
        throw EM_ID_OUT_OF_BOUNDS;

    return _values.at(id);
}