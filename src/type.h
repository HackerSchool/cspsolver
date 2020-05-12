#ifndef TYPE_H
#define TYPE_H

class Type {
public:
    enum TypeId {ID_INTEGER, ID_SET, ID_BOOL};
public:
    static Type INTEGER;
    static Type SET;
    static Type BOOL;
private:
    TypeId _id;
public:
    Type (TypeId id) : _id(id) {}
    virtual bool equals (Type* type);
};

#endif
