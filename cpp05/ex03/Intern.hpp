#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
	public:
		Intern();
		Intern(const Intern &src);
		~Intern();
		Intern &operator=(const Intern &src);

		AForm *makeForm(const std::string &formName, const std::string &target);

	private:
		AForm* createPresidential(std::string target);
		AForm* createRobotomy(std::string target);
		AForm* createShrubbery(std::string target);

		class FormNotFoundException : public std::exception {
			public:
				const char *what() const throw();
		};
};

#endif
