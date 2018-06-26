/*
 * 1. Create operand template
 * 2. Create instance of operand
*/

#include <cstdlib>
#include <climits>
#include "Operand.tmp.hpp"
#include "eOperandType.hpp"
#include "Comp.tmp.hpp"

void addDiffTypes()
{
	std::cout << "-------------AddDiffTypes--------------" << std::endl;
	Operand<int16_t> *op1 = new Operand<int16_t>(20, eOperandType::INT_32);
	Operand<int32_t> *op2 = new Operand<int32_t>(5, eOperandType::INT_32);
	std::cout << "this is the value string " << op2->toString() << std::endl;
	Operand<double> *op3 = new Operand<double>(25.2369, eOperandType::DOUBLE);
	std::cout << "this is the value string " << op3->toString() << std::endl;
	delete op2;
	try {
		const Operand<double> *plus = dynamic_cast<Operand<double> const * >(*op1 + *op3);
		std::cout << "result of 20 + 5 is: " << plus->toString() << std::endl;
	} catch (std::exception & e) {
		std::cout << "Exception in addDiffTypes: " << e.what() << std::endl;
	}
}

void testOperators()
{
	std::cout << "-------------testOperators--------------" << std::endl;
	Operand<int32_t> *op1 = new Operand<int32_t>(20, eOperandType::INT_32);
	Operand<int32_t> *op2 = new Operand<int32_t>(5, eOperandType::INT_32);
	Operand<int32_t> *op3 = new Operand<int32_t>(13, eOperandType::INT_32);
	Operand<int32_t> *op4 = new Operand<int32_t>(0, eOperandType::INT_32);
	Operand<int32_t> *op5 = new Operand<int32_t>(-3, eOperandType::INT_32);
	try {
		const Operand<int32_t> *plus = dynamic_cast<Operand<int32_t> const * >(*op1 + *op2);
		std::cout << "result of 20 + 5 is: " << static_cast<int>(plus->getValue()) << std::endl;
		delete plus;
		const Operand<int32_t> *x = dynamic_cast<Operand<int32_t> const * >(*op1 * *op2);
		std::cout << "result of 20 + 5 is: " << static_cast<int>(x->getValue()) << std::endl;
		delete x;
		const Operand<int32_t> *div = dynamic_cast<Operand<int32_t> const * >(*op1 / *op2);
		std::cout << "result of 20 / 5 is: " << static_cast<int>(div->getValue()) << std::endl;
		delete div;
		const Operand<int32_t> *mod = dynamic_cast<Operand<int32_t> const * >(*op1 % *op2);
		std::cout << "result of 20 % 5 is: " << static_cast<int>(plus->getValue()) << std::endl;
		delete mod;
		const Operand<int32_t> *mod2 = dynamic_cast<Operand<int32_t> const * >(*op3 % *op5);
		std::cout << "result of 13 % -3 is: " << static_cast<int>(plus->getValue()) << std::endl;
		delete mod2;
		const Operand<int32_t> *div2 = dynamic_cast<Operand<int32_t> const * >(*op3 / *op4);
		std::cout << "result of 20 / 5 is: " << static_cast<double>(div->getValue()) << std::endl;
		delete div2;
	}
	catch (std::exception & e) {
		std::cout << "Exception in TestOperators: " << e.what() << std::endl;
	}
}

void testMaxeOperand()
{
	std::cout << "-------------testMaxeOperand--------------" << std::endl;
	eOperandType o1(eOperandType::INT_16);
	eOperandType o2(eOperandType::INT_32);

	std::cout << "Max between INT_16 and INT_32 is " << Comp::max(o1, o2).getType() << std::endl;
}

void testIntOverflow()
{
	std::cout << "-------------TestIntOverFlow1--------------" << std::endl;
	Operand<int8_t> *op1 = new Operand<int8_t>(CHAR_MAX, eOperandType::INT_8);
	Operand<int8_t> *op2 = new Operand<int8_t>(34, eOperandType::INT_8);
	try {	
		const Operand<int8_t> *ret = dynamic_cast<Operand<int8_t> const * >(*op1 * *op2);
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
		const Operand<int8_t> *ret = dynamic_cast<Operand<int8_t> const * >(*op3 * *op4);
		delete ret;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	delete op3;
	delete op4;
	
	std::cout << "-------------TestIntOverFlow3--------------" << std::endl;
	Operand<int8_t> *op5 = new Operand<int8_t>(8, eOperandType::INT_8);
	Operand<int8_t> *op6 = new Operand<int8_t>(6, eOperandType::INT_8);
	try {	
		const Operand<int8_t> *ret = dynamic_cast<Operand<int8_t> const * >(*op5 * *op6);
		std::cout << "result of 8 x 6 is: " << static_cast<int>(ret->getValue()) << std::endl;
		delete ret;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	delete op5;
	delete op6;
}

void testDoubleOverflow()
{
	std::cout << "-------------TestDoubelOverFlow1--------------" << std::endl;
	Operand<double> *op1 = new Operand<double>(DBL_MAX, eOperandType::DOUBLE);
	Operand<double> *op2 = new Operand<double>(34, eOperandType::DOUBLE);
	try {	
		const Operand<double> *ret = dynamic_cast<Operand<double> const * >(*op1 + *op2);
		delete ret;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	delete op1;
	delete op2;
	
	std::cout << "-------------TestDoubelOverFlow2--------------" << std::endl;
	Operand<double> *op3 = new Operand<double>(-1, eOperandType::DOUBLE);
	Operand<double> *op4 = new Operand<double>(-DBL_MAX, eOperandType::DOUBLE);
	try {	
		const Operand<double> *ret = dynamic_cast<Operand<double> const * >(*op1 + *op2);
		delete ret;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	delete op3;
	delete op4;
	
	std::cout << "-------------TestDoubelOverFlow3--------------" << std::endl;
	Operand<double> *op5 = new Operand<double>(-DBL_MIN, eOperandType::DOUBLE);
	Operand<double> *op6 = new Operand<double>(-DBL_MIN, eOperandType::DOUBLE);
	try {
		const Operand<double> *ret = dynamic_cast<Operand<double> const * >(*op1 + *op2);
		std::cout << "result of 20 + 22 is: " << static_cast<double>(ret->getValue()) << std::endl;
		delete ret;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	delete op5;
	delete op6;
	
	std::cout << "-------------TestDoubelOverFlow4--------------" << std::endl;
	Operand<double> *op7 = new Operand<double>(22, eOperandType::DOUBLE);
	Operand<double> *op8 = new Operand<double>(20, eOperandType::DOUBLE);
	try {	
		const Operand<double> *ret = dynamic_cast<Operand<double> const * >(*op1 + *op2);
		std::cout << "result of 20 + 22 is: " << static_cast<double>(ret->getValue()) << std::endl;
		delete ret;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	delete op7;
	delete op8;
}


int main ()
{
	testMaxeOperand();
	testIntOverflow();
	testDoubleOverflow();
	testOperators(); 
	addDiffTypes();
	return 0;
}
