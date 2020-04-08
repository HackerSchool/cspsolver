#ifndef TYPE_H
#define TYPE_H

class Type {
public:
    enum TypeId {ID_INTEGER, ID_DOMAIN};
public:
    static Type INTEGER;
    static Type DOMAIN;
private:
    TypeId _id;
public:
    Type (TypeId id) : _id(id) {}
    virtual bool equals (Type* type) {
        return this->_id == type->_id; 
    }
};

#endif