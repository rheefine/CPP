#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	public:
		AForm();
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		AForm(const AForm &src);
		virtual ~AForm();
		AForm &operator=(const AForm &src);

		void beSigned(Bureaucrat &bureaucrat);
		std::string getName() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		bool getIsSigned() const;
		virtual void execute(Bureaucrat const &executor) const = 0;

	protected:
		class GradeTooHighException: public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class NoSignedException: public std::exception {
			public:
				virtual const char *what() const throw();
		};

	private:
		const std::string _name;
		const int _gradeToSign;
		const int _gradeToExecute;
		bool _isSigned;
};

std::ostream &operator<<(std::ostream &out, const AForm &src);

#endif
