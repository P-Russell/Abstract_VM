#ifndef ERROR_HPP
#define ERROR_HPP

#include <iostream>
#include <exception>

class Error {
	public:
		class divide_by_zero : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Error: divide by zero";
				}
		};
		class modulo_by_zero : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Error: modulo by zero";
				}
		};
		class not_enough_operands : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Error: not enough operands on stack";
				}
		};
		class assert_fail : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Error: assert false";
				}
		};
		class empty_stack : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Error: empty stack";
				}
		};
		class empty_file : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Error: empty file";
				}
		};
		class invalid_file_name: public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Error: invalid file name";
				}
		};
		class invalid_syntax: public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Error: invalid syntax";
				}
		};
		class print_fail: public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Error: last item on stack not int8";
				}
		};
		virtual const char* what() const throw() { 
			return "Error: Unknown Error!"; 
		}
};

#endif
