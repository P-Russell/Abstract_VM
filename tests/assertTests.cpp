#include <cstdlib>
#include <climits>
#include "Operand.tmp.hpp"
#include "eOperandType.hpp"
#include "Factory.hpp"
#include "Stack.hpp"
#include "gtest/gtest.h"

TEST(assertFloat, types1)
{
	Factory fa;
    Stack stack;
	eOperandType f(eOperandType::FLOAT);
	eOperandType d(eOperandType::DOUBLE);

    stack.push(fa.createOperand(f, "5"));
    stack.push(fa.createOperand(d, "2"));
    stack.divide();
	EXPECT_TRUE(stack.assertThat(fa.createOperand(d, "2.5")));
}

TEST(assertInt, types1)
{
	Factory fa;
    Stack stack;
	eOperandType i32(eOperandType::INT_32);
	eOperandType i16(eOperandType::INT_16);

    stack.push(fa.createOperand(i32, "5"));
    stack.push(fa.createOperand(i16, "2"));
    stack.divide();
	EXPECT_TRUE(stack.assertThat(fa.createOperand(i32, "2")));
}

TEST(assertThrow, types1)
{
	Factory fa;
    Stack stack;
	eOperandType f(eOperandType::FLOAT);
	eOperandType d(eOperandType::DOUBLE);

    stack.push(fa.createOperand(d, "10"));
    EXPECT_THROW(stack.assertThat(fa.createOperand(f, "10")), Error::assert_fail);
    EXPECT_THROW(stack.assertThat(fa.createOperand(eOperandType::INT_16, "10")), Error::assert_fail);
    EXPECT_TRUE(stack.assertThat(fa.createOperand(d, "10")));
}