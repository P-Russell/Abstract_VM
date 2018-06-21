/*
 * 1. Create operand template
 * 2. Create instance of operand
*/

#include <cstdlib>
#include "Operand.tmp.hpp"

int main ()
{
	Operand<int> *i = new Operand<int>(56);

	Operand<int> cpy = *i;

	std::cout << i->getPrecision() << " " << i->getValue() << std::endl;
	
	Operand<int8_t> *k = new Operand<int8_t>(127);

	std::cout << k->getPrecision() << " " << static_cast<int>(k->getValue()) << std::endl;
	
	Operand<int32_t> *j = new Operand<int32_t>(8);

	std::cout << j->getPrecision() << " " << j->getValue() << std::endl;

	
	std::cout << "-------------Copy Constructor--------------" << std::endl;

	Operand<int> rig(32);
	Operand<int> lef = rig;

	std::cout << "Rig:  " << rig.getPrecision() << " " << rig.getValue() << std::endl;
	std::cout << "Lef:  " << lef.getPrecision() << " " << lef.getValue() << std::endl;

	(void)rig;
	(void)lef;

	std::cout << "-------------Assignment Constructor--------------" << std::endl;

	Operand<int> rig1(32);
	Operand<int> lef1(24);

	lef1 = rig1;

	std::cout << "Rig:  " << rig1.getPrecision() << " " << rig1.getValue() << std::endl;
	std::cout << "Lef:  " << lef1.getPrecision() << " " << lef1.getValue() << std::endl;

	(void)rig1;
	(void)lef1;
	
	return 0;
}
