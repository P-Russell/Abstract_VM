#ifndef INPUT_HPP
#define INPUT_HPP

#include <fstream>
#include <iostream>
#include <string>
#include <list>

#include "Error.hpp"
#include "Line.hpp"

class Input {
	public:
		Input();
		~Input();
		Input(const Input & rhs);
		Input & operator = (const Input & rhs);
		void saveLine(Line * line);
		void dumpLines();
		bool getLinesFromFile(std::string filename);
		bool validateLine(Line * line_struct);
		void checkExit();
		bool moreToExec();
		bool isComment(std::string &s);
		Line * getNext();
	private:
		std::list< Line * > _lines;
};

#endif