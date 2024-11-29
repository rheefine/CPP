#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &src) { *this = src; }

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &src) {
	(void)src;
	return *this;
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) {
	const std::string formNames[3] = {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};

	AForm* (Intern::*forms[3])(std::string) = {
		&Intern::createPresidential,
		&Intern::createRobotomy,
		&Intern::createShrubbery
	};

	for (int i = 0; i < 3; i++) {
		if (formName == formNames[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*forms[i])(target);
		}
	}
	throw Intern::FormNotFoundException();
}

AForm *Intern::createPresidential(std::string target) {
	return new PresidentialPardonForm(target);
}

AForm *Intern::createRobotomy(std::string target) {
	return new RobotomyRequestForm(target);
}

AForm *Intern::createShrubbery(std::string target) {
	return new ShrubberyCreationForm(target);
}

const char *Intern::FormNotFoundException::what() const throw() {
	return "Form not found";
}
