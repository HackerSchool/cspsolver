#ifndef TYPE_H
#define TYPE_H

class Type {
public:
    enum TypeId {ID_INTEGER};
public:
    static Type INTEGER;
private:
    TypeId _id;
public:
    Type (TypeId id) : _id(id) {}
    virtual bool equals (Type* type) {
        return this->_id == type->_id; 
    }
};

#endif