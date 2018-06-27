#include <cstdlib>
#include <climits>
#include "Operand.tmp.hpp"
#include "eOperandType.hpp"
#include "Factory.hpp"
#include "Stack.hpp"
#include "gtest/gtest.h"

int main (int ac, char ** av)
{
	testing::InitGoogleTest(&ac, av);
	return RUN_ALL_TESTS();
}
