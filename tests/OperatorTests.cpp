#include <cstdlib>
#include <climits>
#include "Operand.tmp.hpp"
#include "eOperandType.hpp"
#include "Factory.hpp"
#include "Stack.hpp"
#include "gtest/gtest.h"

TEST(can_subtract_diff_types, types1)
{
	Factory fa;
	eOperandType i8(eOperandType::INT_8);
	eOperandType i16(eOperandType::INT_16);
	eOperandType i32(eOperandType::INT_32);
	eOperandType f(eOperandType::FLOAT);
	eOperandType d(eOperandType::DOUBLE);

	EXPECT_EQ((*fa.createOperand(d, "25.5") - *fa.createOperand(i16, "20"))->toString(), "5.500000");
	EXPECT_EQ((*fa.createOperand(i32, "25") - *fa.createOperand(f, "20.0"))->toString(), "5.000000");
	EXPECT_TRUE((*fa.createOperand(i32, "25") - *fa.createOperand(f, "20.0"))->getType() == eOperandType::FLOAT);
	EXPECT_THROW((*fa.createOperand(i32, std::to_string(-INT_MAX)) - *fa.createOperand(i32, "20"))->toString(), std::overflow_error);
}

TEST(can_multiply_diff_types, types1)
{
	Factory fa;
	eOperandType i8(eOperandType::INT_8);
	eOperandType i16(eOperandType::INT_16);
	eOperandType i32(eOperandType::INT_32);
	eOperandType f(eOperandType::FLOAT);
	eOperandType d(eOperandType::DOUBLE);

	EXPECT_EQ((*fa.createOperand(i32, "5") * *fa.createOperand(i16, "20"))->toString(), "100");
	EXPECT_EQ((*fa.createOperand(i32, "5") * *fa.createOperand(f, "-20"))->toString(), "-100.000000");
	EXPECT_TRUE((*fa.createOperand(i32, "25") * *fa.createOperand(f, "20"))->getType() == eOperandType::FLOAT);
	EXPECT_THROW((*fa.createOperand(i32, std::to_string(INT_MAX)) * *fa.createOperand(i32, "2"))->toString(), std::overflow_error);
}

TEST(can_add_diff_types, types1)
{
	Factory fa;
	eOperandType i8(eOperandType::INT_8);
	eOperandType i16(eOperandType::INT_16);
	eOperandType i32(eOperandType::INT_32);
	eOperandType f(eOperandType::FLOAT);
	eOperandType d(eOperandType::DOUBLE);

	EXPECT_EQ((*fa.createOperand(i8, "25") + *fa.createOperand(i16, "20"))->toString(), "45");
	EXPECT_EQ((*fa.createOperand(i32, "25") + *fa.createOperand(f, "20"))->toString(), "45.000000");
	EXPECT_TRUE((*fa.createOperand(i32, "25") + *fa.createOperand(f, "20"))->getType() == eOperandType::FLOAT);
	EXPECT_THROW((*fa.createOperand(i32, std::to_string(INT_MAX)) + *fa.createOperand(i32, "20"))->toString(), std::overflow_error);
}

TEST(can_divide_diff_types, types1)
{
	Factory fa;
	eOperandType i8(eOperandType::INT_8);
	eOperandType i16(eOperandType::INT_16);
	eOperandType i32(eOperandType::INT_32);
	eOperandType f(eOperandType::FLOAT);
	eOperandType d(eOperandType::DOUBLE);

	EXPECT_EQ((*fa.createOperand(i8, "5") / *fa.createOperand(i16, "2"))->toString(), "2");
	EXPECT_EQ((*fa.createOperand(i32, "25") / *fa.createOperand(f, "-5"))->toString(), "-5.000000");
	EXPECT_TRUE((*fa.createOperand(i32, "25") / *fa.createOperand(f, "20"))->getType() == eOperandType::FLOAT);
	EXPECT_THROW((*fa.createOperand(i32, std::to_string(INT_MAX)) / *fa.createOperand(i32, "0"))->toString(), Error::divide_by_zero);
}

TEST(can_modulo_diff_types, types1)
{
	Factory fa;
	eOperandType i8(eOperandType::INT_8);
	eOperandType i16(eOperandType::INT_16);
	eOperandType i32(eOperandType::INT_32);
	eOperandType f(eOperandType::FLOAT);
	eOperandType d(eOperandType::DOUBLE);

	EXPECT_EQ((*fa.createOperand(i8, "25") % *fa.createOperand(i16, "23"))->toString(), "2");
	EXPECT_EQ((*fa.createOperand(i32, "25") % *fa.createOperand(f, "-23"))->toString(), "2.000000");
	EXPECT_TRUE((*fa.createOperand(i32, "25") % *fa.createOperand(f, "20"))->getType() == eOperandType::FLOAT);
	EXPECT_THROW((*fa.createOperand(i32, std::to_string(INT_MAX)) % *fa.createOperand(i32, "0"))->toString(), Error::modulo_by_zero);
}