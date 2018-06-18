/*
 * 1. Create operand template
 * 2. Create instance of operand
*/

#include "Operand.tmp.hpp"

int main ()
{
	Operand<int> *i = new Operand<int>(56);

	std::cout << i->getPrecision() << " " << i->getValue() << std::endl;
	
	return 0;
}
