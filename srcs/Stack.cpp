#include "Stack.hpp"

Stack::Stack() {}

Stack::~Stack()
{
	std::list<const IOperand *>::iterator it;
	for (it = _stack.begin(); it !=  _stack.end() ; it++)
		delete *it;
	_stack.clear();
}

Stack::Stack(const Stack & rhs)
{
	this->_stack = rhs._stack;
}

Stack & Stack::operator = (const Stack & rhs)
{
	this->_stack = rhs._stack;
	return *this;
}

size_t Stack::size() { return _stack.size(); }

void Stack::push(IOperand const * operand)
{
	_stack.push_back(operand);
}

IOperand const * Stack::pop()
{
	if (_stack.size() <= 0)
		throw Error::empty_stack();
	const IOperand *op = _stack.back();
	_stack.pop_back();

	return (op);
}

void Stack::dump()
{
	std::list<const IOperand *>::iterator it;
	for (it = _stack.begin(); it !=  _stack.end() ; it++)
		std::cout << (*it)->toString() << std::endl;
}

void Stack::add()
{
	if (_stack.size() < 2)
		throw Error::not_enough_operands();
	const IOperand *op1 = _stack.back();
	_stack.pop_back();
	const IOperand *op2 = _stack.back();
	_stack.pop_back();
	
	_stack.push_back(*op1 + *op2);
	
	delete op1;
	delete op2;
}

void Stack::subtract()
{
	if (_stack.size() < 2)
		throw Error::not_enough_operands();
	const IOperand *op1 = _stack.back();
	_stack.pop_back();
	const IOperand *op2 = _stack.back();
	_stack.pop_back();
	
	_stack.push_back(*op2 - *op1);
	
	delete op1;
	delete op2;
}

void Stack::multiply()
{
	if (_stack.size() < 2)
		throw Error::not_enough_operands();
	const IOperand *op1 = _stack.back();
	_stack.pop_back();
	const IOperand *op2 = _stack.back();
	_stack.pop_back();
	
	_stack.push_back(*op1 * *op2);
	
	delete op1;
	delete op2;
}

void Stack::divide()
{
	if (_stack.size() < 2)
		throw Error::not_enough_operands();
	const IOperand *op1 = _stack.back();
	_stack.pop_back();
	const IOperand *op2 = _stack.back();
	_stack.pop_back();
	try {	
		_stack.push_back(*op2 / *op1);
		delete op1;
		delete op2;
	} catch (std::exception & e)
	{
		_stack.push_back(op2);
		_stack.push_back(op1);
		throw Error::divide_by_zero();
	}
}

void Stack::modulo()
{
	if (_stack.size() < 2)
		throw Error::not_enough_operands();
	const IOperand *op1 = _stack.back();
	_stack.pop_back();
	const IOperand *op2 = _stack.back();
	_stack.pop_back();
	
	try {	
		_stack.push_back(*op2 % *op1);
		delete op1;
		delete op2;
	} catch (std::exception & e)
	{
		_stack.push_back(op2);
		_stack.push_back(op1);
		throw Error::modulo_by_zero();
	}
}

bool Stack::assertThat(IOperand const * operand)
{
	const IOperand * cmp = _stack.back();
	if (cmp->getType() != operand->getType() || 
			cmp->toString().compare(operand->toString()) != 0)
		throw Error::assert_fail();
	
	return true;
}
