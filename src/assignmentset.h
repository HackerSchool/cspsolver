#ifndef ASSIGNMENT_SET_H
#define ASSIGNMENT_SET_H
#include <vector>
#include "value.h"

class VariableSet;

class AssignmentSet {
private:
    int _nextAssign;
    int _assignedCount;
    std::vector<std::shared_ptr<Value>> _values;
public:
    AssignmentSet(int count);
    
    // check if the variable is assigned
    bool assigned(int _id);

    // get the value of a variable
    std::shared_ptr<Value> value(int _id);

    // checks if all the variables are assigned
    bool isCompleteAssignment ();

    // sort variables for the selectUnassigned() 
    void sortVariables ();

    // selects one variable that is unassigned
    int selectUnassigned ();

    // assign a variable
    void assign (int var, std::shared_ptr<Value> value);

    // unassign a variable
    void unassign (int var);

    //print
    std::string toString (VariableSet* set);

private:
    // throw exception if invalid id
    void checkId (int id);

};

#endif