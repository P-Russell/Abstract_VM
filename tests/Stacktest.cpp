#include <cstdlib>
#include <climits>
#include "Operand.tmp.hpp"
#include "eOperandType.hpp"
#include "Factory.hpp"
#include "Stack.hpp"

#include "gtest/gtest.h"

TEST(can_subtract_on_stack, set1)
{
	Factory fa;
	Stack stack;
	
	stack.push(fa.createOperand(eOperandType::INT_8, "10"));
	stack.push(fa.createOperand(eOperandType::INT_16, "5"));
	stack.subtract();
	EXPECT_EQ(std::stoi(stack.pop()->toString()), 5);
	stack.push(fa.createOperand(eOperandType::FLOAT, "24"));
	stack.push(fa.createOperand(eOperandType::INT_8, "18"));
	stack.subtract();
	EXPECT_EQ(std::stod(stack.pop()->toString()), 6);
}

TEST(can_divide_on_stack, set1)
{
	Factory fa;
	Stack stack;
	
	stack.push(fa.createOperand(eOperandType::INT_8, "10"));
	stack.push(fa.createOperand(eOperandType::INT_16, "5"));
	stack.divide();
	EXPECT_EQ(std::stoi(stack.pop()->toString()), 2);
	stack.push(fa.createOperand(eOperandType::FLOAT, "24"));
	stack.push(fa.createOperand(eOperandType::INT_8, "18"));
	stack.divide();
	EXPECT_EQ(std::stod(stack.pop()->toString()), 1.333333);
}

TEST(can_add_on_stack, set1)
{
	Factory fa;
	Stack stack;
	
	stack.push(fa.createOperand(eOperandType::INT_8, "8"));
	stack.push(fa.createOperand(eOperandType::INT_16, "16"));
	stack.add();
/*	
	std::cout << "----------StackDump--------------" << std::endl;
	stack.dump();
	std::cout << "----------StackDump--------------" << std::endl;
*/
	EXPECT_EQ(std::stoi(stack.pop()->toString()), 24);
	stack.push(fa.createOperand(eOperandType::FLOAT, "18"));
	stack.push(fa.createOperand(eOperandType::INT_8, "24"));
	stack.add();
	EXPECT_EQ(std::stod(stack.pop()->toString()), 42);
}

TEST(can_push_to_stack, types1)
{
	Factory fa;
	Stack stack;
	eOperandType i8(eOperandType::INT_8);
	eOperandType i16(eOperandType::INT_16);
	eOperandType i32(eOperandType::INT_32);
	eOperandType f(eOperandType::FLOAT);
	eOperandType d(eOperandType::DOUBLE);

	stack.push(fa.createOperand(i8, "8"));
	stack.push(fa.createOperand(i16, "16"));
	stack.push(fa.createOperand(i32, "32"));
	stack.push(fa.createOperand(f, "563.562356"));
	stack.push(fa.createOperand(d, "563.562356"));
	EXPECT_EQ((int)stack.size(), 5);
}