template <class T>
IOperand const * Operand<T>::operator % (IOperand const & rhs) const {

	if (std::stod(rhs.toString()) == 0)
		throw Error::modulo_by_zero();

	eOperandType resultType;

	if (rhs.getType() > this->getType())
		resultType = rhs.getType();
	else
		resultType = this->getType();

	if(resultType == eOperandType::INT_8 || resultType == eOperandType::INT_16 || resultType == eOperandType::INT_32) {
		long val = std::stol(rhs.toString());
		return factory.createOperand(resultType, std::to_string(this->_value - std::floor(this->_value / val) * val));
	}

	double val = std::stod(rhs.toString());
	return factory.createOperand(resultType, std::to_string(std::fmod(this->_value, val)));
}
