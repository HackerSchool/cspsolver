#ifndef SET_LITERAL_H
#define SET_LITERAL_H
#include "expression.h"
#include "setvalue.h"

class SetLiteral : public Expression {
private:
    std::shared_ptr<SetValue> _value;
public:
    SetLiteral(std::vector<Expression*> *list);
    SetLiteral();
    std::shared_ptr<Value> eval(AssignmentSet *set) { return _value; }
    void check (AssignmentSet *set) { this->setType(&Type::SET); }
};

#endif