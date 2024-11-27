#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src), _target(src._target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src) {
	if (this != &src) {
		_target = src._target;
	}
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (!getIsSigned()) {
		throw NoSignedException();
	}
	if (executor.getGrade() > getGradeToExecute()) {
		throw GradeTooLowException();
	}
	std::cout << _target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
