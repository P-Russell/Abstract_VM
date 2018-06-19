#include <iostream>

template <class T>
class Operand {

public:
	Operand<T>(void);
	Operand<T>(T value): _value(value), _precision(sizeof(value)) {}
	~Operand<T>(void); 
	Operand & operator=(const Operand<T> & rhs);
	Operand<T>(const Operand & rhs) : _value(rhs._value), _precision(rhs._precision) {}
	int getPrecision(void) { return this->_precision; }
	T getValue(void) { return _value; }
private:
	const T _value;
	const int _precision;
};

