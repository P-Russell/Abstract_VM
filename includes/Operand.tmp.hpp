#ifndef OPERAND_TMP_HPP
#define OPERAND_TMP_HPP

#include <iostream>
#include <cfloat>
#include <limits>
#include <stdexcept>
#include <climits>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <string>
#include <cmath>

#include "IOperand.hpp"
#include "eOperandType.hpp"
#include "Error.hpp"
#include "Factory.hpp"

class Factory;

template <class T>
class Operand : public IOperand {

	public:
		Operand<T>(void) {}
		Operand<T>(T value, int type, std::string valueString): _value(value), _precision(type), _valueString(valueString) {
			this->_type.setType(type);
		}					
		Operand<T>(T value, eOperandType type, std::string valueString): _value(value), _precision(type.getType()), _valueString(valueString) {
			this->_type = type;
	}					
	~Operand<T>(void) {}

	Operand & operator=(const Operand<T> & rhs) {
		this->_value = rhs._value;
		this->_precision = rhs._precision;
		this->_valueString = rhs._valueString;
		this->_type = rhs._type;
			return *this;
		};

		Operand<T>(const Operand & rhs) : _value(rhs._value), _precision(rhs._precision) {}

		virtual int getPrecision(void) const { return this->_precision; }

		virtual eOperandType getType(void) const { return this->_type; }

		T getValue(void) const { return _value; }

		virtual IOperand const * operator + (IOperand const & rhs) const;
		virtual IOperand const * operator - (IOperand const & rhs) const;
		virtual IOperand const * operator * (IOperand const & rhs) const;
		virtual IOperand const * operator / (IOperand const & rhs) const;
		virtual IOperand const * operator % (IOperand const & rhs) const;
		
		virtual std::string const & toString(void) const { return _valueString; }

	private:
		T _value;
		int _precision;
		std::string _valueString;
		eOperandType _type;
		Factory factory;
};

#include "operators/Operand.add.hpp"
#include "operators/Operand.subtract.hpp"
#include "operators/Operand.multiply.hpp"
#include "operators/Operand.divide.hpp"
#include "operators/Operand.modulo.hpp"

#endif
