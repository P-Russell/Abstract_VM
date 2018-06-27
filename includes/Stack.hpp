#ifndef STACK_HPP
#define STACK_HPP

#include <vector>
#include <iostream>
#include "IOperand.hpp"
#include "Error.hpp"


class Stack {
public:
	void push(IOperand const * operand);
	void add();
	void subtract();
	void multiply();
	void divide();
	void modulo();
	void dump();
	size_t size();
private:
	std::vector<IOperand const *> _stack;
};

#endif
