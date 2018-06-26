#ifndef OPERAND_MULTIPLY_HPP
#define OPERAND_MULTIPLY_HPP

template< class T >
IOperand const * Operand<T>::operator * (IOperand const & rhs) const {

	eOperandType resultType;
	if (rhs.getType() > this->getType()) 
		resultType = rhs.getType();
	else 
		resultType = this->getType();

	if(resultType == eOperandType::INT_8) {
		int8_t rhs8 = std::stoi(rhs.toString());

		if (rhs8 > CHAR_MAX / this->_value)
			throw std::overflow_error("Overflow occured");
		else if (rhs8 < CHAR_MIN / this->_value)
			throw std::overflow_error("Overflow occured");

		return new Operand<int8_t>(rhs8 * this->_value, resultType);
	}

	else if(resultType == eOperandType::INT_16) {
		int16_t rhs16 = std::stoi(rhs.toString());
		if  (rhs16 > SHRT_MAX / this->_value)
			throw std::overflow_error("Overflow occured");
		else if (rhs16 < SHRT_MIN / this->_value)
			throw std::underflow_error("Underflow occured");

		return new Operand<int16_t>(this->_value * rhs16, resultType);
	}

	else if(resultType == eOperandType::INT_32) {
		int32_t rhs32 = std::stoi(rhs.toString());
		if (rhs32 > INT_MAX / this->_value)
			throw std::overflow_error("Overflow occured");
		else if (rhs32 < INT_MIN / this->_value)
			throw std::underflow_error("Underflow occured");

		return new Operand<int32_t>(this->_value * rhs32, resultType);
	}

	else if(resultType == eOperandType::FLOAT) {
		float rhsF = std::stof(rhs.toString());
		if (rhsF > FLT_MAX / this->_value)
			throw std::overflow_error("Overflow occured");
		else if (rhsF < -FLT_MAX / this->_value)
			throw std::underflow_error("Underflow occured");
//		else if (rhsF < FLT_MIN / this->_value)
//			throw std::underflow_error("Underflow occured");

		return new Operand<float>(this->_value * rhsF, resultType);
	}

	double rhsD = std::stod(rhs.toString());
	if (rhsD > DBL_MAX / this->_value)
		throw std::overflow_error("Overflow occured");
	else if (rhsD < -DBL_MAX / this->_value)
		throw std::underflow_error("Underflow occured");
//	else if (rhsD < DBL_MIN / this->_value)
//		throw std::underflow_error("Underflow occured");

	return new Operand<double>(this->_value * rhsD, resultType);

}

#endif
