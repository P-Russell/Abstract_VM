/*
 * 1. Create operand template
 * 2. Create instance of operand
*/
#include <cstdlib>
#include <climits>
#include "Operand.tmp.hpp"
#include "eOperandType.hpp"
#include "Comp.tmp.hpp"
#include "Factory.hpp"
#include "gtest/gtest.h"


TEST(can_create_int8, types1)
{
	Factory fa;
	eOperandType type(eOperandType::INT_8);

	EXPECT_EQ(fa.createOperand(type, "25")->toString(), "25");
	EXPECT_THROW(fa.createOperand(type, std::to_string(CHAR_MAX + 1)), std::overflow_error);
	EXPECT_THROW(fa.createOperand(type, std::to_string(CHAR_MIN - 1)), std::underflow_error);
}


TEST(can_create_double, types1)
{
	Factory fa;
	eOperandType type(eOperandType::DOUBLE);

	EXPECT_EQ(fa.createOperand(type, "25")->toString(), "25.000000");
	EXPECT_THROW(fa.createOperand(type, std::to_string(DBL_MAX + 6000000)), std::overflow_error);
//	EXPECT_THROW(fa.createOperand(type, std::to_string(-DBL_MAX)), std::underflow_error);
}

int main (int ac, char ** av)
{
	testing::InitGoogleTest(&ac, av);
	std::cout << CHAR_MAX <<std::endl;
	return RUN_ALL_TESTS();
}

