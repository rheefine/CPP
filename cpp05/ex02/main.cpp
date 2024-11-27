#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
	Bureaucrat b1("b1", 1);
	ShrubberyCreationForm form("home1");
	RobotomyRequestForm form2("Robot1");
	PresidentialPardonForm form3("Zaphod Beeblebrox1");

	b1.signForm(form);
	b1.executeForm(form);

	b1.signForm(form2);
	b1.executeForm(form2);

	b1.signForm(form3);
	b1.executeForm(form3);

	Bureaucrat b2("b2", 150);
	ShrubberyCreationForm form4("home2");
	RobotomyRequestForm form5("Robo2t");
	PresidentialPardonForm form6("Zaphod Beeblebrox2");

	b2.signForm(form4);
	b2.executeForm(form4);

	b2.signForm(form5);
	b2.executeForm(form5);

	b2.signForm(form6);
	b2.executeForm(form6);

	return (0);
}
