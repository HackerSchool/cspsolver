#include "setliteral.h"
#include "assignmentset.h"

SetLiteral::SetLiteral(std::vector<Expression*> *list) : Expression() {
    AssignmentSet set (0);
    std::vector<std::shared_ptr<Value>> values;

    for (Expression* e : *list) {
        e->check(nullptr); //FIXME
        values.push_back(e->eval(&set));
    }

    _value = std::make_shared<SetValue> (values);
    setType(&Type::SET);
}

SetLiteral::SetLiteral() {
    _value = std::make_shared<SetValue> ();
    setType(&Type::SET);
}