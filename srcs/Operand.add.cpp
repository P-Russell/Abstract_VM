#include "Operand.tmp.hpp"

#ifndef OPERAND_ADD_CPP
#define OPERAND_ADD_CPP

/*
template< class T >
T Operand<T>::getValue(void) const { return this->_value; }
*/
template< class T >
IOperand const * Operand<T>::operator + (IOperand const & rhs) const {
	//handel overflow/underflow
	const Operand &tmp = dynamic_cast<const Operand &>(rhs);
	if (tmp.getType() > this->getType())
		return new Operand(this->getValue() + 
				tmp.getValue(), tmp.getType());
	return new Operand(this->getValue() + 
			tmp.getValue(), this->getType());
}

#endif
