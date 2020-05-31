#ifndef UNASSIGNED_VARIABLE_H
#define UNASSIGNED_VARIABLE_H

#include <exception>

class UnassignedVariable : public std::exception {
public:
    virtual const char* what() const throw() {
        return "eval variable but it is not assigned";
    }
};

#endif