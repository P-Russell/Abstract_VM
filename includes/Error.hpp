#ifndef ERROR_HPP
#define ERROR_HPP

#include <iostream>
#include <exception>

class Error {
	public:
		class divide_by_zero : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "divide by zero";
				}
		};
		class modulo_by_zero : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "modulo by zero";
				}
		};
		class not_enough_operands : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "not enough operands on stack";
				}
		};
		class assert_fail : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "assert false";
				}
		};
		class empty_stack : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "pop on empty stack";
				}
		};
		virtual const char* what() const throw() { 
			return "Unknown Error!"; 
		}
};

#endif
