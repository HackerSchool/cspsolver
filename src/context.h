#ifndef CONTEXT_H
#define CONTEXT_H
#include <vector>
#include "value.h"

class Context {
private:
    std::vector<std::shared_ptr<Value>> _values;
public:
    Context();
    bool assigned(int _id);
    std::shared_ptr<Value> value(int _id);
    void assign(int _id, std::shared_ptr<Value> value);
};

#endif