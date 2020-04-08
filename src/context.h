#ifndef CONTEXT_H
#define CONTEXT_H
#include <vector>
#include "value.h"

class Context {
private:
    std::vector<Value*> _values;
public:
    Context();
    bool assigned(int _id);
    Value *value(int _id);
    void assign(int _id, Value *value);
};

#endif