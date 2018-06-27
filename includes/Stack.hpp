#ifndef STACK_HPP
#define STACK_HPP

#include <list>
#include <iostream>
#include "IOperand.hpp"
#include "Error.hpp"


class Stack {
public:
	//add constructor, destructor, assignment and copy constructor
	Stack();
	~Stack();

	void push(IOperand const * operand);
	void add();
	void subtract();
	void multiply();
	void divide();
	void modulo();
	void dump();
	void assert();
	size_t size();
	void pop();
	void assert(IOperand const * operand);
private:
	std::list<IOperand const *> _stack;
};

#endif
