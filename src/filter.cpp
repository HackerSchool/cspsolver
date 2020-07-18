#include "filter.h"
#include "assignmentset.h"
#include "errormessage.h"
#include "integervalue.h"
#include "literal.h"
#include "boolvalue.h"

Filter::Filter(Expression* exp, const std::string& id, 
        Expression* set, Expression* cond): 
    Expression(), _exp(exp), _id(id), _set(set), _cond(cond)  {

    if (_cond == nullptr) {
        _cond = new Literal(new BoolValue(true));
    }
}

std::shared_ptr<Value> Filter::eval(AssignmentSet *set) {
    std::vector<std::shared_ptr<Value>> values;
    std::shared_ptr<SetValue> setValue;
    std::shared_ptr<BoolValue> boolValue;

    // build the filter
    setValue = std::dynamic_pointer_cast<SetValue> (_set->eval(set));
    boolValue = std::dynamic_pointer_cast<BoolValue> (_cond->eval(set));

    for (int i = begin->value(); i < end->value(); i += step->value()) 
        values.push_back(std::make_shared<IntegerValue>(i));

    return std::make_shared<SetValue> (values);
}

void Filter::check (VariableSet *set) {
    // check expression
    _exp->check(set);

    // check set
    _set->check(set);
    if (_set->getType()->id() != Type::ID_SET)
        throw EM_FILTER_TYPES;
    
    // check condition
    _cond->check(set);
    if (_cond->getType()->id() != Type::ID_BOOL)
        throw EM_FILTER_TYPES;

    // range is a set   
    setType(&Type::SET);
}