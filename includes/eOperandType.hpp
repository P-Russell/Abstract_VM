#ifndef EOPERANDTYPE_HPP
#define EOPERANDTYPE_HPP

class eOperandType {
public:
	eOperandType(int type = DOUBLE): _type(type) {}
	~eOperandType(void) {}
	eOperandType(const eOperandType & rhs) : _type(rhs._type) {}
	eOperandType & operator = (const eOperandType & rhs);
	eOperandType & operator = (const int & rhs);
	int getType(void);
	enum _types
	{
		INT_8,
		INT_16,
		INT_32,
		FLOAT,
		DOUBLE
	};
private:
	int _type;
};

#endif
