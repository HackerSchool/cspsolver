#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <set>
#include <algorithm>
#include <iterator>

class Type;
class Value {
public:
    Value *add(Value *other);
};
class Context {
public:
    bool assigned(int _id);
    Value *value(int _id);
    void assign(int _id, Value *value);
};

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

    virtual Value *eval(Context *ctx) = 0;
};

#endif