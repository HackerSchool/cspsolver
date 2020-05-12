#include "context.h"

Context::Context() {
    
}

bool Context::assigned(int _id) {
    if(_values.size() > _id)
        return _values[_id] != nullptr;
    else
        throw "Context: bound error.";
}

std::shared_ptr<Value> Context::value(int _id) {
    if(_values.size() > _id)
        return _values[_id];
    else
        throw "Context: bound error.";
}

void Context::assign(int _id, std::shared_ptr<Value> value) {
    if(_values.size() > _id)
        _values[_id] = value;
    else
        throw "Context: bound error.";
}