#include <cstdlib>
#include <fstream>
#include <iostream>
#include "Operand.tmp.hpp"
#include "eOperandType.hpp"
#include "Stack.hpp"
#include "Factory.hpp"
#include "Input.hpp"
#include "Line.hpp"
/*
void execInstruction(Line * instruction)
{
}
*/
int main (int argc, char **argv)
{
	Input input;
	bool valid;
	Line userInput;
	if (argc == 2) {
		try {
			valid = input.getLinesFromFile(argv[1]);
//			input.dumpLines();
		} catch (Error::invalid_file_name & e) {
			std::cout << e.what() << std::endl;
		}
		if (valid)
			std::cout << "Totally valid file";
	}
	else 
	{
		std::cout << "Reading from stdin." << std::endl;
		int linesRead = 1;
		while(true) {
			std::getline(std::cin, userInput.line);
			userInput.line_num = linesRead++;
			
			if (userInput.line.compare(";;") == 0)
				break;
			
			try {
				input.validateLine(&userInput);
				Line *validated = new Line;
				*validated = userInput;
				input.saveLine(validated);
			} catch (Error::invalid_syntax & e) {
				std::cout << e.what() << std::endl;
			}
		}
//		input.dumpLines();
	}
	try {
		input.checkExit();
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
