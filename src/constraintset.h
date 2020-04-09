#ifndef CONSTRAINT_SET_H
#define CONSTRAINT_SET_H
#include <vector>
#include "constraint.h"

class ConstraintSet {
private:
    std::vector<Constraint*> _vector;
public:
    ConstraintSet() {}
    void add (Constraint* def) {_vector.push_back(def);}
};

#endif