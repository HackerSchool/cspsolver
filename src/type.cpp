#include "type.h"

Type Type::INTEGER (ID_INTEGER);
Type Type::SET (ID_SET);
Type Type::BOOL (ID_BOOL);

bool Type::equals (Type* type) {
    return this->_id == type->_id; 
}
