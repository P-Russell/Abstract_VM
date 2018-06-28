#include "eOperandType.hpp"

int eOperandType::getType(void) const { return _type; }

eOperandType & eOperandType::operator = (const eOperandType & rhs) {
	this->_type = rhs._type;
	return *this;
}

eOperandType & eOperandType::operator = (const int & rhs) {
	this->_type = rhs;
	return *this;
}

eOperandType::~eOperandType() {}

void eOperandType::setType(int type){
	this->_type = type;
}

bool eOperandType::operator==( eOperandType const & rhs ) { return (this->_type == rhs._type); }
bool eOperandType::operator!=( eOperandType const & rhs ) { return (this->_type != rhs._type); } 
bool eOperandType::operator>( eOperandType const & rhs ) { return (this->_type > rhs._type); }
bool eOperandType::operator<( eOperandType const & rhs ) { return (this->_type < rhs._type); } 
bool eOperandType::operator>=( eOperandType const & rhs ) { return (this->_type >= rhs._type); }
bool eOperandType::operator<=( eOperandType const & rhs ) { return (this->_type <= rhs._type); }
