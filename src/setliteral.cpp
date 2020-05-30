#include "setliteral.h"

SetLiteral::SetLiteral(std::vector<Expression*> *list) : Expression() {
    AssignmentSet set (0);
    std::vector<std::shared_ptr<Value>> values;

    for (Expression* e : *list) {
        e->check(&set);
        values.push_back(e->eval(&set));
    }

    _value = std::make_shared<SetValue> (values);
}

SetLiteral::SetLiteral() {
    _value = std::make_shared<SetValue> ();
}