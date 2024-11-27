#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {

	try {
		Form f0("f0", 50, 50);
		std::cout << f0;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		Form f1("f1", 0, 50);
		std::cout << f1;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		Form f2("f2", 50, 0);
		std::cout << f2;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		Form f3("f3", 151, 50);
		std::cout << f3;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		Form f4("f4", 50, 151);
		std::cout << f4;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	Bureaucrat b0("b0", 51);
	Form f0("f0", 50, 50);

	b0.signForm(f0);
	b0.incrementGrade();
	b0.signForm(f0);
	b0.signForm(f0);

}
