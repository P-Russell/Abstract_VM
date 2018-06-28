#include "Line.hpp"

Line::Line() {}
Line::~Line() {}

Line::Line(const Line &rhs)
{
	this->line_num = rhs.line_num;
	this->line = rhs.line;
	this->value = rhs.value;
	this->type = rhs.type;
	this->operation = rhs.operation;
}

Line &Line::operator=(const Line &rhs)
{
	this->line_num = rhs.line_num;
	this->line = rhs.line;
	this->value = rhs.value;
	this->type = rhs.type;
	this->operation = rhs.operation;
	return *this;
}