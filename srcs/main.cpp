#include <cstdlib>
#include <fstream>
#include <iostream>
#include "Operand.tmp.hpp"
#include "eOperandType.hpp"
#include "Stack.hpp"
#include "Factory.hpp"
#include "Input.hpp"

int main (int argc, char **argv)
{
	Input input;
	bool valid;
	if (argc == 2) {
		try {
			valid = input.getLinesFromFile(argv[1]);
			input.dumpLines();
		} catch (Error::invalid_file_name & e) {
			std::cout << e.what() << std::endl;
		}
		if (valid)
			std::cout << "Totally valid file";
	}
	return 0;
}
