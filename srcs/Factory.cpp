#include "Factory.hpp"
#include "Operand.tmp.hpp"

Factory::Factory() {}
Factory::~Factory() {}
Factory::Factory(const Factory &) {}
Factory &Factory::operator=(const Factory &) { return *this; }

IOperand const *Factory::createInt8(std::string const &value) const
{
	long val = std::stol(value);

	if (val > CHAR_MAX)
		throw std::overflow_error("Overflow occured");
	else if (val < CHAR_MIN)
		throw std::underflow_error("Underflow occured");

	return new Operand<int8_t>(val, eOperandType::INT_8, value);
}

IOperand const *Factory::createInt16(std::string const &value) const
{
	long val = std::stol(value);

	if (val > SHRT_MAX)
		throw std::overflow_error("Overflow occured");
	else if (val < SHRT_MIN)
		throw std::underflow_error("Underflow occured");

	return new Operand<int16_t>(val, eOperandType::INT_16, value);
}

IOperand const *Factory::createInt32(std::string const &value) const
{
	long val = std::stol(value);

	if (val > INT_MAX)
		throw std::overflow_error("Overflow occured");
	else if (val < INT_MIN)
		throw std::underflow_error("Underflow occured");

	return new Operand<int32_t>(val, eOperandType::INT_32, value);
}

IOperand const *Factory::createFloat(std::string const &value) const
{
	double val = std::stold(value);

	if (val > FLT_MAX)
		throw std::overflow_error("Overflow occured");
	else if (val <= -FLT_MAX)
		throw std::underflow_error("Underflow occured");

	return new Operand<float>(std::stof(value), eOperandType::FLOAT, value);
}

IOperand const *Factory::createDouble(std::string const &value) const
{
	return new Operand<double>(std::stod(value), eOperandType::DOUBLE, value);
}

IOperand const *Factory::createOperand(eOperandType type, std::string const &value) const
{
	createOp creatOpArray[] = {
		&Factory::createInt8,
		&Factory::createInt16,
		&Factory::createInt32,
		&Factory::createFloat,
		&Factory::createDouble};

	createOp func = creatOpArray[type.getType()];
	return (this->*func)(value);
}