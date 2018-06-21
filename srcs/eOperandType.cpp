#include "eOperandType.hpp"

int eOperandType::getType(void) { return _type; }

eOperandType & eOperandType::operator = (const eOperandType & rhs) {
	this->_type = rhs._type;
	return *this;
}
