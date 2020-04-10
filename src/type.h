#ifndef TYPE_H
#define TYPE_H

class Type {
public:
    enum TypeId {ID_INTEGER, ID_DOMAIN, ID_BOOL};
public:
    static Type INTEGER;
    static Type DOMAIN;
    static Type BOOL;
private:
    TypeId _id;
public:
    Type (TypeId id) : _id(id) {}
    virtual bool equals (Type* type) {
        return this->_id == type->_id; 
    }
};

#endif