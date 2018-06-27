#include "Factory.hpp"
#include "Operand.tmp.hpp"

IOperand const * Factory::createOperand( eOperandType type, std::string const & value ) const 
{
	int make = type.getType();
	switch(make) {
		case eOperandType::INT_8:
			return Factory::createInt8(value);
		case eOperandType::INT_16:
			return Factory::createInt16(value);
		case eOperandType::INT_32:
			return Factory::createInt32(value);
		case eOperandType::FLOAT:
			return Factory::createFloat(value);
		case eOperandType::DOUBLE:
			return Factory::createDouble(value);
		default:
			return Factory::createDouble(value);
	}
}

IOperand const * Factory::createInt8( std::string const & value ) const
{
	long val = std::stol(value);

	if (val > CHAR_MAX)
		throw std::overflow_error("Overflow occured");
	else if (val < CHAR_MIN)
		throw std::underflow_error("Underflow occured");
	
	return new Operand<int8_t>(val, eOperandType::INT_8);
}

IOperand const * Factory::createInt16( std::string const & value ) const
{
	long val = std::stol(value);

	if (val > SHRT_MAX)
		throw std::overflow_error("Overflow occured");
	else if (val < SHRT_MIN)
		throw std::underflow_error("Underflow occured");
	
	return new Operand<int16_t>(std::stoi(value), eOperandType::INT_16);
}

IOperand const * Factory::createInt32( std::string const & value ) const
{
	long val = std::stol(value);

	if (val > INT_MAX)
		throw std::overflow_error("Overflow occured");
	else if (val < INT_MIN)
		throw std::underflow_error("Underflow occured");
	
	return new Operand<int32_t>(std::stoi(value), eOperandType::INT_32);
}

IOperand const * Factory::createFloat( std::string const & value ) const 
{
	long double val = std::stold(value);
	
	if (val > FLT_MAX)
		throw std::overflow_error("Overflow occured");
	else if (val <= -FLT_MAX)
		throw std::underflow_error("Underflow occured");
	
	return new Operand<float>(std::stof(value), eOperandType::FLOAT);
}

IOperand const * Factory::createDouble( std::string const & value ) const
{
	return new Operand<double>(std::stod(value), eOperandType::DOUBLE);
}

