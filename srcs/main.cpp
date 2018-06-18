/*
 * 1. Create operand template
 * 2. Create instance of operand
*/

#include <cstdlib>
#include "Operand.tmp.hpp"

int main ()
{
	Operand<int> *i = new Operand<int>(56);

	std::cout << i->getPrecision() << " " << i->getValue() << std::endl;
	
	Operand<int8_t> *k = new Operand<int8_t>(127);

	std::cout << k->getPrecision() << " " << static_cast<int>(k->getValue()) << std::endl;
	
	Operand<int32_t> *j = new Operand<int32_t>(8);

	std::cout << j->getPrecision() << " " << j->getValue() << std::endl;
	
	return 0;
}
