#include "Bureaucrat.hpp"
#include "Intern.hpp"
/*
#include <cstdlib>
void checkleak(void) {
	system("leaks ex03");
}
*/
int main(void) {
//	atexit(checkleak);
	Intern someRandomIntern;
	Bureaucrat b1("b1", 2);
	AForm* rrf;
	AForm* rrf2;
	AForm* rrf3;
	AForm* rrf4;


	try {
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *rrf;
		rrf->beSigned(b1);
		rrf->execute(b1);
		delete rrf;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		rrf2 = someRandomIntern.makeForm("presidential pardon", "Bender");
		std::cout << *rrf2;
		rrf2->beSigned(b1);
		rrf2->execute(b1);
		delete rrf2;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		rrf3 = someRandomIntern.makeForm("shrubbery creation", "Bender");
		std::cout << *rrf3;
		rrf3->beSigned(b1);
		rrf3->execute(b1);
		delete rrf3;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

		std::cout << std::endl;

	try {
		rrf4 = someRandomIntern.makeForm("Invalid Form", "Bender");
		std::cout << *rrf4;
		rrf4->beSigned(b1);
		rrf4->execute(b1);
		delete rrf4;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
