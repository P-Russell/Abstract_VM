#include <iostream>
#include <exception>

class Error {
	public:
		class Negative : public std::exception {
			public:
				virtual const char* what() const throw() {
						return "given a negative number.";
				}
		};
		class Positive : public std::exception {
			public:
				virtual const char* what() const throw() {
						return "given a postive number.";
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
}*/
