#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	if (grade < 1) {
		throw GradeTooHighException();
	} else if (grade > 150) {
		throw GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) {
	if (this != &src) {
		_grade = src._grade;
	}
	return *this;
}

void Bureaucrat::incrementGrade() {
	if (_grade - 1 < 1) {
		throw GradeTooHighException();
	}
	_grade--;
}

void Bureaucrat::decrementGrade() {
	if (_grade + 1 > 150) {
		throw GradeTooLowException();
	}
	_grade++;
}

void Bureaucrat::signForm(AForm &form) {
	if (form.getIsSigned())
		std::cout << _name << " already signed " << form.getName() << "."<< std::endl;
	else {
		try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << "." << std::endl;
		} catch (std::exception &e) {
			std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
		}
	}
}

void Bureaucrat::executeForm(AForm &form) {
	try {
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	} catch (std::exception &e) {
		std::cout << _name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

std::string Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &src) {
	out << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;
	return out;
}
