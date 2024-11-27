#include "AForm.hpp"

AForm::AForm() : _name("default"), _gradeToSign(150), _gradeToExecute(150), _isSigned(false) {}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _isSigned(false) {
	if (gradeToSign < 1 || gradeToExecute < 1) {
		throw GradeTooHighException();
	} else if (gradeToSign > 150 || gradeToExecute > 150) {
		throw GradeTooLowException();
	}
}

AForm::AForm(const AForm &src) : _name(src._name), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute), _isSigned(src._isSigned) {}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &src) {
	if (this != &src) {
		_isSigned = src._isSigned;
	}
	return *this;
}

void AForm::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign) {
		throw GradeTooLowException();
	}
	_isSigned = true;
}

std::string AForm::getName() const {
	return _name;
}

int AForm::getGradeToSign() const {
	return _gradeToSign;
}

int AForm::getGradeToExecute() const {
	return _gradeToExecute;
}

bool AForm::getIsSigned() const {
	return _isSigned;
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

const char *AForm::NoSignedException::what() const throw() {
	return "Form is not signed!";
}

std::ostream &operator<<(std::ostream &out, const AForm &src) {
	out << src.getName()
		<< ", grade to sign: " << src.getGradeToSign()
		<< ", grade to execute: " << src.getGradeToExecute()
		<< ", is signed: " << (src.getIsSigned() ? "true" : "false") << std::endl;
	return out;
}

