#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <list>

class Type;
class Value;
class Context;

class Expression {
private:
    Type *_type;
public:
    Expression(Type *type = nullptr) : _type(type) {}
    void setType(Type *type) { _type = type; }
    Type *getType() { return _type; }
    virtual Value *eval(Context *ctx) = 0;
    virtual const std::list<int> &getVariables() = 0;
};

#endif