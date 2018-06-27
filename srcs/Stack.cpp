#include "Stack.hpp"


void Stack::push(IOperand const * operand)
{
	_stack.push_back(operand);
}

void Stack::add()
{
	if (_stack.size() < 2)
		throw Error::not_enough_operands();
/*	const IOperand *op1 = _stack.pop_back();
	const IOperand *op2 = _stack.pop_back();

	_stack.push_back(*op1 + *op2);
	
	delete op1;
	delete op2;*/
}

size_t Stack::size() { return _stack.size(); }

void Stack::dump()
{
	for (size_t i = 0; i < _stack.size(); i++)
		std::cout << _stack[i]->toString() << std::endl;
}
/*
void Stack::subtract();
void Stack::multiply();
void Stack::divide();
void Stack::modulo();
*/
