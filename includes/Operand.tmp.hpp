#include <iostream>
#include <sstream>
#include "IOperand.hpp"

template <class T>
class Operand : public IOperand {

public:
	Operand<T>(void);
	Operand<T>(T value): _value(value), _precision(sizeof(value)) {}
	~Operand<T>(void) {} 
	Operand & operator=(const Operand<T> & rhs) {
		this->_value = rhs._value;
		this->_precision = rhs._precision;
		return *this;
	};
	Operand<T>(const Operand & rhs) : _value(rhs._value), _precision(rhs._precision) {
	}

	int getPrecision(void) const { return this->_precision; }

	T getValue(void) { return _value; }


	IOperand const * operator + (IOperand const & rhs) const {
		(void)rhs;
		return this;
	}
	IOperand const * operator - (IOperand const & rhs) const {
		(void)rhs;
		return this;
	}
	IOperand const * operator * (IOperand const & rhs) const {
		(void)rhs;
		return this;
	}
	IOperand const * operator / (IOperand const & rhs) const {
		(void)rhs;
		return this;
	}
	IOperand const * operator % (IOperand const & rhs) const {
		(void)rhs;
		return this;
	}

	std::string const & toString(void) const
	{
		std::stringstream ss;
		ss << "Address: " << this;
		ss << " Value: " << this->_value;
		ss << " Precision: " << this->_precision;
		const std::string *ret = new std::string(ss.str());
		return *ret;
	}

private:
	T _value;
	int _precision;
};

