#ifndef LINE_HPP
#define LINE_HPP

#include <string>

class Line
{
public:
	int line_num;
	std::string line;
	std::string value;
	int type;
	std::string operation;
	Line();
	~Line();
	Line & operator = (const Line & rhs);
	Line(const Line & rhs);
};

#endif