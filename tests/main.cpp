/*
 * 1. Create operand template
 * 2. Create instance of operand
*/

#include <cstdlib>
#include "Operand.tmp.hpp"
#include "eOperandType.hpp"
#include "Comp.tmp.hpp"
#include <climits>

void testMaxeOperand()
{
	std::cout << "-------------testMaxeOperand--------------" << std::endl;
	eOperandType o1(eOperandType::INT_16);
	eOperandType o2(eOperandType::INT_32);

	std::cout << "Max between INT_16 and INT_32 is " << Comp::max(o1, o2).getType() << std::endl;
}

void testIntOverFlow()
{
	std::cout << "-------------TestIntOverFlow1--------------" << std::endl;
	Operand<int8_t> *op1 = new Operand<int8_t>(CHAR_MAX, eOperandType::INT_8);
	Operand<int8_t> *op2 = new Operand<int8_t>(34, eOperandType::INT_8);
	try {	
		const Operand<int8_t> *ret = dynamic_cast<Operand<int8_t> const * >(*op1 + *op2);
		delete ret;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	delete op1;
	delete op2;
	
	std::cout << "-------------TestIntOverFlow2--------------" << std::endl;
	Operand<int8_t> *op3 = new Operand<int8_t>(CHAR_MIN, eOperandType::INT_8);
	Operand<int8_t> *op4 = new Operand<int8_t>(-34, eOperandType::INT_8);
	try {	
		const Operand<int8_t> *ret = dynamic_cast<Operand<int8_t> const * >(*op3 + *op4);
		delete ret;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	delete op3;
	delete op4;
	
	std::cout << "-------------TestIntOverFlow3--------------" << std::endl;
	Operand<int8_t> *op5 = new Operand<int8_t>(20, eOperandType::INT_8);
	Operand<int8_t> *op6 = new Operand<int8_t>(22, eOperandType::INT_8);
	try {	
		const Operand<int8_t> *ret = dynamic_cast<Operand<int8_t> const * >(*op5 + *op6);
		std::cout << "result of 20 + 22 is: " << static_cast<int>(ret->getValue()) << std::endl;
		delete ret;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	delete op5;
	delete op6;
}

int main ()
{
	testMaxeOperand();
	testIntOverFlow();
	return 0;
}
