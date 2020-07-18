#include "range.h"
#include "assignmentset.h"
#include "errormessage.h"
#include "integervalue.h"
#include "literal.h"

Range::Range(Expression* begin, Expression* end, Expression* step): 
    Expression(), _begin(begin), _end(end), _step(step)  {

    if (_step == nullptr)
        _step = new Literal(new IntegerValue(1));
}

std::shared_ptr<Value> Range::eval(AssignmentSet *set) {
    std::vector<std::shared_ptr<Value>> values;
    std::shared_ptr<IntegerValue> begin, end, step;

    // build the range
    begin = std::dynamic_pointer_cast<IntegerValue> (_begin->eval(set));
    end = std::dynamic_pointer_cast<IntegerValue> (_end->eval(set));
    step = std::dynamic_pointer_cast<IntegerValue> (_step->eval(set));

    for (int i = begin->value(); i < end->value(); i += step->value()) 
        values.push_back(std::make_shared<IntegerValue>(i));

    return std::make_shared<SetValue> (values);
}

void Range::check (VariableSet *set) {
    // check begin expression
    _begin->check(set);
    if (_begin->getType()->id() != Type::ID_INTEGER)
        throw EM_RANGE_TYPES;

    // check end expression
    _end->check(set);
    if (_end->getType()->id() != Type::ID_INTEGER)
        throw EM_RANGE_TYPES;
    
    // check step expression
    _step->check(set);
    if (_step->getType()->id() != Type::ID_INTEGER)
        throw EM_RANGE_TYPES;

    // range is a set   
    setType(&Type::SET);
}