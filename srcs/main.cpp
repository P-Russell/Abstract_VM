/*
 * 1. Create operand template
 * 2. Create instance of operand
*/

#include <cstdlib>
#include "Operand.tmp.hpp"

int main ()
{
	
	Operand<int> *op1 = new Operand<int>(34);	
	Operand<int> *op2 = new Operand<int>(24);

	const Operand<int> *sum = dynamic_cast<const Operand<int> *>(*op1 + *op2);
//	const Operand *sum2 = static_cast<const Operand *>(sum);
	std::cout << "-------------Plus Operator--------------" << std::endl;


	std::cout << "Op2:  " << op1->getPrecision() << " " << op1->getValue() << std::endl;
	std::cout << "Op1:  " << op2->getPrecision() << " " << op2->getValue() << std::endl;
	std::cout << "Sum:  " << sum->getPrecision() << " " << sum->getValue() << std::endl;
	(void)sum;
	(void)op1;
	(void)op2;
	
	return 0;
}
