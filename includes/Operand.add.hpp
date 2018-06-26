template< class T >
IOperand const * Operand<T>::operator + (IOperand const & rhs) const {

	eOperandType resultType;
//	Factory factory;

	if (rhs.getType() > this->getType()) 
		resultType = rhs.getType();
	else 
		resultType = this->getType();

	if(resultType == eOperandType::INT_8) {
		int rhs8 = std::stoi(rhs.toString());
		return factory.createOperand(resultType, std::to_string(rhs8 + this->_value));
	}

	else if(resultType == eOperandType::INT_16) {
		int rhs16 = std::stoi(rhs.toString());
		return factory.createOperand(resultType, std::to_string(rhs16 + this->_value));
	}

	else if(resultType == eOperandType::INT_32) {
		int32_t rhs32 = std::stoi(rhs.toString());
		return factory.createOperand(resultType, std::to_string(rhs32 + this->_value));
	}

	else if(resultType == eOperandType::FLOAT) {
		float rhsF = std::stof(rhs.toString());
		return factory.createOperand(resultType, std::to_string(rhsF + this->_value));
	}

	double rhsD = std::stod(rhs.toString());
	return factory.createOperand(resultType, std::to_string(rhsD + this->_value));

}
