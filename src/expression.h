#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <set>
#include <algorithm>
#include "value.h"
#include "context.h"

class Type;

class Expression {
private:
    Type *_type;
protected:
    std::set<int> _variables;
public:
    Expression(Type *type = nullptr) : _type(type) {}
    void setType(Type *type) { _type = type; }
    Type *getType() { return _type; }
    const std::set<int> &getVariables() { return _variables; }

    virtual std::shared_ptr<Value> eval(Context *ctx) = 0;
};

#endif