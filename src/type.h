#ifndef TYPE_H
#define TYPE_H

class Value;

class Type {
public:
    Type () {}
    virtual bool equals (Type* type) {
        return this == type;
    }

    virtual bool addAvailable (Type* right) = 0;
    virtual bool subAvailable (Type* right) = 0;
    virtual bool mulAvailable (Type* right) = 0;
    virtual bool divAvailable (Type* right) = 0;

    virtual Value* add (Value* right) = 0;
    virtual Value* sub (Value* right) = 0;
    virtual Value* mul (Value* right) = 0;
    virtual Value* div (Value* right) = 0;
};

#endif