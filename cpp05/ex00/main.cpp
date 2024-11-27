#include <iostream>
#include "Bureaucrat.hpp"

int main() {

	try {
		Bureaucrat b0("b0", 50);
		std::cout << b0;
		b0.incrementGrade();
		std::cout << b0;
		b0.decrementGrade();
		std::cout << b0;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		Bureaucrat b1("b1", 1);
		std::cout << b1;
		b1.incrementGrade();
		std::cout << b1;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {

		Bureaucrat b2("b2", 150);
		std::cout << b2;
		b2.decrementGrade();
		std::cout << b2;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		Bureaucrat b3("b3", 0);
		std::cout << b3;
	} catch (std::exception &e) {
		std::cout  << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		Bureaucrat b4("b4", 151);
		std::cout << b4;
	} catch (std::exception &e) {
		std::cout  << e.what() << std::endl;
	}

}
