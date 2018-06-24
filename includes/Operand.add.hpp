#include "Operand.tmp.hpp"

#ifndef OPERAND_ADD_CPP
#define OPERAND_ADD_CPP

#include <stdexcept>
#include <climits>

template< class T >
IOperand const * Operand<T>::operator + (IOperand const & rhs) const {

	const Operand &tmp = dynamic_cast<const Operand &>(rhs);

	eOperandType resultType;
	if (tmp.getType() > this->getType()) 
		resultType = tmp.getType();
	else 
		resultType = this->getType();

	if(resultType == eOperandType::INT_8) {
		if ((tmp.getValue() > 0) && (tmp.getValue() > CHAR_MAX - this->getValue()))
			throw std::overflow_error("Overflow occured");
		else if ((tmp.getValue() < 0) && (tmp.getValue() < CHAR_MIN - this->getValue()))
			throw std::underflow_error("Underflow occured");
	}

	if(resultType == eOperandType::INT_16) {
		if ((tmp.getValue() > 0) && (tmp.getValue() > CHAR_MAX - this->getValue()))
			throw std::overflow_error("Overflow occured");
		else if ((tmp.getValue() < 0) && (tmp.getValue() < CHAR_MIN - this->getValue()))
			throw std::underflow_error("Underflow occured");
	}

	if (tmp.getType() > this->getType())
		return new Operand(this->getValue() + 
				tmp.getValue(), tmp.getType());
	else
		return new Operand(this->getValue() + 
				tmp.getValue(), this->getType());
}

#endif
