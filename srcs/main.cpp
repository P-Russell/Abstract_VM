/*
 * 1. Create operand template
 * 2. Create instance of operand
*/

#include <cstdlib>
#include "Operand.tmp.hpp"
#include "eOperandType.hpp"

int main ()
{
	Operand<int> *op = new Operand<int>(34, eOperandType::INT_16);
	(void)op;
	/*
	Operand<int> *op1 = new Operand<int>(34, eOperandType(eOperandType::INT16);	
	Operand<int> *op2 = new Operand<int>(24);

	const Operand<int> *sum = dynamic_cast<const Operand<int> *>(*op1 + *op2);
	std::cout << "-------------Plus Operator--------------" << std::endl;


	std::cout << "Op2:  " << op1->getPrecision() << " " << op1->getValue() << std::endl;
	std::cout << "Op1:  " << op2->getPrecision() << " " << op2->getValue() << std::endl;
	std::cout << "Sum:  " << sum->getPrecision() << " " << sum->getValue() << std::endl;
	delete sum;
	delete op1;
	delete op2;

	std::cout << "int8_t: " << sizeof(int8_t) << std::endl; 
	std::cout << "int16_t: " << sizeof(int16_t) << std::endl; 
	std::cout << "int32_t: " << sizeof(int32_t) << std::endl; 
	std::cout << "float: " << sizeof(float) << std::endl; 
	std::cout << "double: " << sizeof(double) << std::endl; 

		
	eOperandType e(eOperandType::INT_32);
	eOperandType f;

	std::cout << "e: " << e.getType() << " f: " << f.getType() << std::endl; 
	
	eOperandType g = e;
	eOperandType c;

	c = f;
	std::cout << "g: " << g.getType() << " c: " << c.getType() << std::endl;
	std::cout << "-----------------------------------" << std::endl;
*/
	return 0;
}
