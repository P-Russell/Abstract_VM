#include <cstdlib>
#include <climits>
#include "Operand.tmp.hpp"
#include "eOperandType.hpp"
#include "Factory.hpp"
#include "Stack.hpp"

#include "gtest/gtest.h"
TEST(can_create_int8, types1)
{
	Factory fa;
	eOperandType type(eOperandType::INT_8);

	EXPECT_EQ(fa.createOperand(type, "25")->toString(), "25");
	EXPECT_THROW(fa.createOperand(type, std::to_string(CHAR_MAX + 1)), std::overflow_error);
	EXPECT_THROW(fa.createOperand(type, std::to_string(CHAR_MIN - 1)), std::overflow_error);
}

TEST(can_create_double, types1)
{
	Factory fa;
	eOperandType type(eOperandType::DOUBLE);

	EXPECT_EQ(fa.createOperand(type, "25.325")->toString(), "25.325");
}
