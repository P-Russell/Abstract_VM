#ifndef OPERAND_SUBTRACT_HPP
#define OPERAND_SUBTRACT_HPP

template< class T >
IOperand const * Operand<T>::operator - (IOperand const & rhs) const {

	const Operand &tmp = dynamic_cast<const Operand &>(rhs);

	eOperandType resultType;
	if (tmp.getType() > this->getType()) 
		resultType = tmp.getType();
	else 
		resultType = this->getType();

	if(resultType == eOperandType::INT_8) {
		if ((tmp._value > 0) && (tmp._value > CHAR_MAX + this->_value))
			throw std::overflow_error("Overflow occured");
		else if ((tmp._value < 0) && (tmp._value < CHAR_MIN + this->_value))
			throw std::underflow_error("Underflow occured");
	}

	else if(resultType == eOperandType::INT_16) {
		if ((tmp._value > 0) && (tmp._value > SHRT_MAX + this->_value))
			throw std::overflow_error("Overflow occured");
		else if ((tmp._value < 0) && (tmp._value < SHRT_MIN + this->_value))
			throw std::underflow_error("Underflow occured");
	}

	else if(resultType == eOperandType::INT_32) {
		if ((tmp._value > 0) && (tmp._value > INT_MAX + this->_value))
			throw std::overflow_error("Overflow occured");
		else if ((tmp._value < 0) && (tmp._value < INT_MIN + this->_value))
			throw std::underflow_error("Underflow occured");
	}

	else if(resultType == eOperandType::FLOAT) {
		if ((tmp._value > 0) && (tmp._value > FLT_MAX + this->_value))
			throw std::overflow_error("Overflow occured");
		else if ((tmp._value < 0) && (tmp._value < -FLT_MAX + this->_value))
			throw std::underflow_error("Underflow occured");
		else if ((tmp._value < 0) && (tmp._value < FLT_MIN + this->_value))
			throw std::underflow_error("Underflow occured");
	}

	else if(resultType == eOperandType::DOUBLE) {
		if ((tmp._value > 0) && (tmp._value > DBL_MAX + this->_value))
			throw std::overflow_error("Overflow occured");
		else if ((tmp._value < 0) && (tmp._value < -DBL_MAX + this->_value))
			throw std::underflow_error("Underflow occured");
		else if ((tmp._value < 0) && (tmp._value < DBL_MIN + this->_value))
			throw std::underflow_error("Underflow occured");
	}

	return new Operand(this->_value - tmp._value, resultType);
}

#endif
