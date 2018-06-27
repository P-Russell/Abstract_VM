template< class T >
IOperand const * Operand<T>::operator + (IOperand const & rhs) const {

	eOperandType resultType;

	if (rhs.getType() > this->getType()) 
		resultType = rhs.getType();
	else 
		resultType = this->getType();

	if(resultType == eOperandType::INT_8 || resultType == eOperandType::INT_16 || resultType == eOperandType::INT_32) {
		long val = std::stol(rhs.toString());
		return factory.createOperand(resultType, std::to_string(val + this->_value));
	}

	double val = std::stod(rhs.toString());
	if ((val > 0) && (val > DBL_MAX - this->_value))
		throw std::overflow_error("Overflow occured");
	else if ((val < 0) && (val < -DBL_MAX - this->_value))
		throw std::underflow_error("Underflow occured");

	return factory.createOperand(resultType, std::to_string(val + this->_value));
}
