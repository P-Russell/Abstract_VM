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
		class invalid_arguments_for_operation : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "invalid arguments for % operator. Expected discrete values";
				}
		};
		virtual const char* what() const throw() { 
			return "Unknown Error!"; 
		}
};

/*
std::string  check(int i) {
	if (i < 0)
		throw Error::Negative();
	if (i > 0)
		throw Error::Positive();
	return ("True");
}

int main() {
	try {
		std::cout << check(-10) << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
}
*/
