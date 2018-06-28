#include <algorithm>
#include <cctype>
#include <locale>
#include "Input.hpp"
#include "eOperandType.hpp"

Input::Input() {}

Input::~Input()
{
	std::list<Line *>::iterator it;
	for (it = _lines.begin(); it != _lines.end(); it++)
		delete *it;
	this->_lines.clear();
}

Input::Input(const Input &rhs)
{
	this->_lines = rhs._lines;
}

Input &Input::operator=(const Input &rhs)
{
	this->_lines = rhs._lines;
	return *this;
}

// trim from start (in place)
static inline void ltrim(std::string &s)
{
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
				return !std::isspace(ch);
			}));
}

// trim from end (in place)
static inline void rtrim(std::string &s)
{
	s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
				return !std::isspace(ch);
			})
				.base(),
			s.end());
}

// trim from both ends (in place)
static inline void trim(std::string &s)
{
	ltrim(s);
	rtrim(s);
}

bool isComment(std::string &s)
{
	if (s[0] == ';')
	{
		if (s.length() == 1)
			return true;
		if (s[1] == ';')
			return false;
		return true;
	}
	return false;
}

void Input::dumpLines()
{
	std::list<Line *>::iterator it;
	for (it = _lines.begin(); it != _lines.end(); it++)
	{
		if ((*it)->operation.compare("push") == 0 || (*it)->operation.compare("assert") == 0)
			std::cout << "line number:" <<(*it)->line_num << "; Raw input:" << (*it)->line << "; Operation:" << (*it)->operation << 
			"; Type:" << (*it)->type << "; Value:" << (*it)->value << ";" <<  std::endl;
		else
			std::cout << "line number:" << (*it)->line_num << 
			"; Raw input:" << (*it)->line << "; Operation:" << (*it)->operation << ";" <<std::endl;
	}
}

int validType(std::string t)
{
	if (t.compare("int8") == 0)
		return eOperandType::INT_8;
	if (t.compare("int16") == 0)
		return eOperandType::INT_16;
	if (t.compare("int32") == 0)
		return eOperandType::INT_32;
	if (t.compare("float") == 0)
		return eOperandType::FLOAT;
	if (t.compare("double") == 0)
		return eOperandType::DOUBLE;
	return -1;
}

bool validOp(std::string t)
{
	if (t.compare("pop") == 0)
		return true;
	if (t.compare("dump") == 0)
		return true;
	if (t.compare("add") == 0)
		return true;
	if (t.compare("sub") == 0)
		return true;
	if (t.compare("mul") == 0)
		return true;
	if (t.compare("div") == 0)
		return true;
	if (t.compare("mod") == 0)
		return true;
	if (t.compare("print") == 0)
		return true;
	if (t.compare("exit") == 0)
		return true;
	return false;
}

void Input::saveLine(Line * line)
{
	this->_lines.push_back(line);
}

bool Input::validateLine(Line *line_struct)
{
	std::string line = line_struct->line;
	std::string operation;
	if (line.find("push") != std::string::npos || line.find("assert") != std::string::npos)
	{
		if (line.find("push") != std::string::npos)
			operation = "push";
		else
			operation = "assert";

		size_t space;
		if ((space = line.find(" ")) == std::string::npos)
			throw Error::invalid_syntax();

		std::string typeAndValue = line.substr(space, line.length());
		trim(typeAndValue);

		size_t firstParen = typeAndValue.find("(");
		size_t secondParen = typeAndValue.find(")");
		if (firstParen == std::string::npos || secondParen == std::string::npos || firstParen > secondParen)
			throw Error::invalid_syntax();

		std::string type = typeAndValue.substr(0, firstParen);
		trim(type);
		if (validType(type) == -1)
			throw Error::invalid_syntax();

		std::string number = typeAndValue.substr((firstParen + 1), secondParen - firstParen - 1);
		trim(number);

		size_t dataPulled = operation.length() + type.length() + number.length() + 3; 
		if (dataPulled != line.length())
			throw Error::invalid_syntax();

		line_struct->operation = operation;
		line_struct->type = validType(type);
		line_struct->value = number;
		return true;
	}
	if (!validOp(line))
		throw Error::invalid_syntax();

	line_struct->operation = line;
	return true;
}

void Input::checkExit()
{
	Line * line = _lines.back();
	if (line->operation.compare("exit") != 0)
		throw Error::invalid_syntax();
}

Line * Input::getNext()
{
	Line * line = _lines.front();
	_lines.pop_front();
	return line;
}

bool Input::moreToExec()
{
	if (_lines.size() > 0)
		return true;
	return false;
}

bool Input::getLinesFromFile(std::string filename)
{
	std::ifstream ifs(filename);
	if (!ifs.is_open())
		throw Error::invalid_file_name();
	std::string line;
	int i = 1;
	while (std::getline(ifs, line))
	{
		trim(line);
		if (line.length() == 0 || isComment(line))
			;
		else
		{
			size_t semiColon;
			if ((semiColon = line.find(";")) != std::string::npos)
			{
				line = line.substr(0, semiColon);
				trim(line);
			}
			Line *l = new Line;
			l->line = line;
			l->line_num = i;
			_lines.push_back(l);
		}
		i++;
	}
	ifs.close();
	bool flag = true;
	std::list<Line *>::iterator it;
	for (it = _lines.begin(); it != _lines.end(); it++)
		try {
			validateLine((*it));
		} catch (Error::invalid_syntax & e) {
			std::cout << e.what() << " on line " << (*it)->line_num << " : " << (*it)->line << std::endl;
			flag = false;
		}
	
	return flag;
}