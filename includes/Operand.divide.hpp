#ifndef OPERAND_DEVIDE_HPP
#define OPERAND_DEVIDE_HPP

template< class T >
IOperand const * Operand<T>::operator / (IOperand const & rhs) const {

	const Operand &tmp = dynamic_cast<const Operand &>(rhs);

	if (tmp._value == 0)
		throw Error::divide_by_zero();
	
	eOperandType resultType;
	if (tmp.getType() > this->getType()) 
		resultType = tmp.getType();
	else 
		resultType = this->getType();
	
	return new Operand(this->_value / tmp._value, resultType);
}

#endif
