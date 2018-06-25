#ifndef OPERAND_TMP_HPP
#define OPERAND_TMP_HPP

#include <iostream>
#include <cfloat>
#include <limits>
#include <stdexcept>
#include <climits>
#include <sstream>
#include "IOperand.hpp"
#include "eOperandType.hpp"
#include "Error.hpp"

template <class T>
class Operand : public IOperand {

	public:
		Operand<T>(void) {}
		Operand<T>(T value, int type): _value(value), _precision(sizeof(value)) {
			this->_type.setType(type);
		}					
		Operand<T>(T value, eOperandType type): _value(value), _precision(sizeof(value)) {
			this->_type = type;
		}					
		~Operand<T>(void) {}

		Operand & operator=(const Operand<T> & rhs) {
			this->_value = rhs._value;
			this->_precision = rhs._precision;
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

		virtual std::string const & toString(void) const
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
		eOperandType _type;
};

#include "Operand.add.hpp"
#include "Operand.subtract.hpp"
#include "Operand.multiply.hpp"
#include "Operand.divide.hpp"
#include "Operand.modulo.hpp"

#endif
