#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("robotomy request", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("robotomy request", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src), _target(src._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src) {
	if (this != &src) {
		_target = src._target;
	}
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (!getIsSigned()) {
		throw NoSignedException();
	}

	if (executor.getGrade() > getGradeToExecute()) {
		throw GradeTooLowException();
	}
	std::cout << "Drilling noises..." << std::endl;
	if (rand() % 2) {
		std::cout << _target << " has been robotomized successfully." << std::endl;
	} else {
		std::cout << _target << " robotomization failed." << std::endl;
	}
}
