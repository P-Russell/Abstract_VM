#ifndef OPERAND_MODULO_HPP
#define OPERAND_MODULO_HPP

template< class T >
IOperand const * Operand<T>::operator % (IOperand const & rhs) const {

	if (std::stod(rhs.toString()) == 0)
		throw Error::divide_by_zero();

	eOperandType resultType;
	if (rhs.getType() > this->getType()) 
		resultType = rhs.getType();
	else 
		resultType = this->getType();

	if(resultType == eOperandType::INT_8) {
		int8_t rhs8 = std::stoi(rhs.toString());
		return new Operand<int8_t>((this->_value) - std::floor(this->_value/rhs8) * rhs8, resultType);
	}

	else if(resultType == eOperandType::INT_16) {
		int16_t rhs16 = std::stoi(rhs.toString());
		return new Operand((this->_value) - std::floor(this->_value/rhs16) * rhs16, resultType);
		return new Operand<int16_t>(this->_value / rhs16, resultType);
	}

	else if(resultType == eOperandType::INT_32) {
		int32_t rhs32 = std::stoi(rhs.toString());
		return new Operand<int32_t>((this->_value) - std::floor(this->_value/rhs32) * rhs32, resultType);
	}

	else if(resultType == eOperandType::FLOAT) {
		float rhsF = std::stof(rhs.toString());
		return new Operand<float>((this->_value) - std::floor(this->_value/rhsF) * rhsF, resultType);
	}

	double rhsD = std::stod(rhs.toString());
	return new Operand<double>((this->_value) - std::floor(this->_value/rhsD) * rhsD, resultType);
}

#endif
