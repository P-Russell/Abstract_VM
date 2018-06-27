#include "Factory.hpp"
#include "Operand.tmp.hpp"

IOperand const * Factory::createOperand( eOperandType type, std::string const & value ) const 
{
	switch(type.getType()) {
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

//	std::cout << "-------------Factory method INT8 val: " << (int)val << " string " << value << std::endl;
	if (val > CHAR_MAX)
		throw std::overflow_error("Overflow occured");
	else if (val < CHAR_MIN)
		throw std::underflow_error("Underflow occured");
	
	return new Operand<int8_t>(val, eOperandType::INT_8, value);
}

IOperand const * Factory::createInt16( std::string const & value ) const
{
	long val = std::stol(value);

//	std::cout << "-------------Factory method INT16 val: " << val << " string " << value << std::endl;
	if (val > SHRT_MAX)
		throw std::overflow_error("Overflow occured");
	else if (val < SHRT_MIN)
		throw std::underflow_error("Underflow occured");
	
	return new Operand<int16_t>(val, eOperandType::INT_16, value);
}

IOperand const * Factory::createInt32( std::string const & value ) const
{
	long val = std::stol(value);

//	std::cout << "-------------Factory method INT32 val: " << val << " string " << value << std::endl;
	if (val > INT_MAX)
		throw std::overflow_error("Overflow occured");
	else if (val < INT_MIN)
		throw std::underflow_error("Underflow occured");
	
	return new Operand<int32_t>(val, eOperandType::INT_32, value);
}

IOperand const * Factory::createFloat( std::string const & value ) const 
{
	double val = std::stold(value);
	
//	std::cout << "-------------Factory method FLOAT val: " << std::setprecision(8) << std::stod(value) << " string " << value << std::endl;
	if (val > FLT_MAX)
		throw std::overflow_error("Overflow occured");
	else if (val <= -FLT_MAX)
		throw std::underflow_error("Underflow occured");
	
	return new Operand<float>(std::stof(value), eOperandType::FLOAT, value);
}

IOperand const * Factory::createDouble( std::string const & value ) const
{
//	std::cout << "-------------Factory method DOUBLE val: " << std::setprecision(8) << std::stod(value) << " string " << value << std::endl;
	return new Operand<double>(std::stod(value), eOperandType::DOUBLE, value);
}

