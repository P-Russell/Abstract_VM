#ifndef INPUT_HPP
#define INPUT_HPP

#include <fstream>
#include <iostream>
#include <string>
#include <list>

#include "Error.hpp"

typedef struct Line 
{
	int line_num;
	std::string line;
	std::string value;
	std::string type;
	std::string operation;
}Line;

class Input {
	public:
		Input();
		~Input();
		Input(const Input & rhs);
		Input & operator = (const Input & rhs);
		void dumpLines();
		bool getLinesFromFile(std::string filename);
		bool validateLine(Line * line_struct);
	private:
		std::list< Line * > _lines;
};

#endif