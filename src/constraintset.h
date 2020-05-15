#ifndef CONSTRAINT_SET_H
#define CONSTRAINT_SET_H
#include <vector>
#include "constraint.h"

class ConstraintSet {
private:
    std::vector<Constraint*> _vector;
public:
    ConstraintSet() {}
    
    // add constraint
    void add (Constraint* def) {_vector.push_back(def);}
    
    // checks if all constraints in this set are respected
    bool allTrue (AssignmentSet* set);
};

#endif