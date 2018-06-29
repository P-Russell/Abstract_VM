#include <cstdlib>
#include <fstream>
#include <iostream>
#include "Operand.tmp.hpp"
#include "eOperandType.hpp"
#include "Stack.hpp"
#include "Factory.hpp"
#include "Input.hpp"
#include "Line.hpp"

void execInstruction(Input & input)
{
	Stack stack;
	Factory factory;
	Line * line;

	while (input.moreToExec())
	{
		line = input.getNext();
		if (line->operation.compare("pop") == 0) { stack.pop(); }
		else if (line->operation.compare("dump") == 0) { stack.dump(); }
		else if (line->operation.compare("add") == 0) { stack.add(); }
		else if (line->operation.compare("sub") == 0) { stack.subtract(); }
		else if (line->operation.compare("mul") == 0) { stack.multiply(); }
		else if (line->operation.compare("div") == 0) { stack.divide(); }
		else if (line->operation.compare("mod") == 0) { stack.modulo(); }
		else if (line->operation.compare("print") == 0) { stack.print(); }
		else if (line->operation.compare("exit") == 0) { stack.clear(); }
		else if (line->operation.compare("push") == 0) {
			stack.push(factory.createOperand(eOperandType(line->type), line->value));
		}
		else if (line->operation.compare("assert") == 0) {
			stack.assertThat(factory.createOperand(eOperandType(line->type), line->value));
		}
	}
}

int main (int argc, char **argv)
{
	Input input;
	bool valid;
	Line userInput;
	if (argc == 2) {
		try {
			valid = input.getLinesFromFile(argv[1]);
		} catch (Error::invalid_file_name & e) {
			std::cout << e.what() << std::endl;
		}
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

			if (!input.isComment(userInput.line))	
			try {
				input.validateLine(&userInput);
				Line *validated = new Line;
				*validated = userInput;
				input.saveLine(validated);
			} catch (Error::invalid_syntax & e) {
				std::cout << e.what() << std::endl;
			}
		}
	}
	try {
		input.checkExit();
		execInstruction(input);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
