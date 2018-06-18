#include <iostream>

template <typename T>
class Operand {

public:
	Operand<T>(void);
	Operand<T>(T value): _value(value), _precision(sizeof(value)) {}
	~Operand<T>(void) { delete this; }
	//Operand & operator=(const & Operand rhs);
	int getPrecision(void) { return this->_precision; }
	T getValue(void) { return _value; }
private:
	T _value;
	const int _precision;
};

