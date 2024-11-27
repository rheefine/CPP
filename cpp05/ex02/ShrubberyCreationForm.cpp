#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src), _target(src._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src) {
	if (this != &src) {
		_target = src._target;
	}
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (!getIsSigned()) {
		throw NoSignedException();
	}

	if (executor.getGrade() > getGradeToExecute()) {
		throw GradeTooLowException();
	}

	std::ofstream file((_target + "_shrubbery").c_str());
	if (!file.is_open()) {
		std::cout << "Error: could not open file." << std::endl;
		throw std::exception();
	}
		file << "				.o00o" << std::endl;
		file << "				o000000oo" << std::endl;
		file << "				00000000000o" << std::endl;
		file << "				00000000000000" << std::endl;
		file << "			oooooo  00000000  o88o" << std::endl;
		file << "		ooOOOOOOOoo  ```''  888888" << std::endl;
		file << "		OOOOOOOOOOOO'.qQQQQq. `8888'" << std::endl;
		file << "		oOOOOOOOOOO'.QQQQQQQQQQ/.88'" << std::endl;
		file << "		OOOOOOOOOO'.QQQQQQQQQQ/ /q" << std::endl;
		file << "		OOOOOOOOO QQQQQQQQQQ/ /QQ" << std::endl;
		file << "		OOOOOOOOO `QQQQQQ/ /QQ'" << std::endl;
		file << "			OO:F_P:O `QQQ/  /Q'" << std::endl;
		file << "				\\\\. \\ |  // |" << std::endl;
		file << "				d\\ \\\\\\|_////" << std::endl;
		file << "				qP| \\\\ _' `|Ob" << std::endl;
		file << "				\\  / \\  \\Op" << std::endl;
		file << "				|  | O| |" << std::endl;
		file << "		_       /\\. \\_/ /\\" << std::endl;
		file << "			`---__/|_\\\\   //|  __" << std::endl;
		file << "				`-'  `-'`-'-'" << std::endl;
		file.close();
}
