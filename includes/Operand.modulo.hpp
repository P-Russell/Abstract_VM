#ifndef OPERAND_MODULO_CPP
#define OPERAND_MODULO_CPP

#include <functional>
#include <cmath>
template< class T >
IOperand const * Operand<T>::operator % (IOperand const & rhs) const {

	const Operand &tmp = dynamic_cast<const Operand &>(rhs);

	if (tmp._value == 0)
		throw Error::divide_by_zero();
	
	eOperandType resultType;
	if (tmp.getType() > this->getType()) 
		resultType = tmp.getType();
	else 
		resultType = this->getType();
//((a/b) - floor(a/b))*b
	if (resultType == eOperandType::DOUBLE || 
			resultType == eOperandType::FLOAT)
		throw Error::invalid_arguments_for_operation();
	
	//return new Operand(std::modulus(this->_value, tmp._value), resultType);
	//return new Operand((this->_value/tmp._value) - std::floor(this->_value/tmp._value) * tmp._value, resultType);
	return new Operand((this->_value) - std::floor(this->_value/tmp._value) * tmp._value, resultType);
}

#endif
