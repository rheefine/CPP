#include "Form.hpp"

Form::Form() : _name("default"), _gradeToSign(150), _gradeToExecute(150), _isSigned(false) {}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _isSigned(false) {
	if (gradeToSign < 1 || gradeToExecute < 1) {
		throw GradeTooHighException();
	} else if (gradeToSign > 150 || gradeToExecute > 150) {
		throw GradeTooLowException();
	}
}

Form::Form(const Form &src) : _name(src._name), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute), _isSigned(src._isSigned) {}

Form::~Form() {}

Form &Form::operator=(const Form &src) {
	if (this != &src) {
		_isSigned = src._isSigned;
	}
	return *this;
}

void Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign) {
		throw GradeTooLowException();
	}
	_isSigned = true;
}

std::string Form::getName() const {
	return _name;
}

int Form::getGradeToSign() const {
	return _gradeToSign;
}

int Form::getGradeToExecute() const {
	return _gradeToExecute;
}

bool Form::getIsSigned() const {
	return _isSigned;
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &out, const Form &src) {
	out << src.getName()
		<< ", grade to sign: " << src.getGradeToSign()
		<< ", grade to execute: " << src.getGradeToExecute()
		<< ", is signed: " << (src.getIsSigned() ? "true" : "false") << std::endl;
	return out;
}

