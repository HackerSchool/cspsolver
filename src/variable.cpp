#include "variable.h"
#include "errormessage.h"
#include "assignmentset.h"

std::shared_ptr<SetValue> Variable::evalDomain () { 
    AssignmentSet set(0);

    if (_domainExp->getType()->id() != Type::ID_SET)
        throw EM_VARID_ID_NOT_SETTED;

    return std::dynamic_pointer_cast<SetValue> (_domainExp->eval(&set));
}

void Variable::checkDomain () {
    _domainExp->check(nullptr);
}