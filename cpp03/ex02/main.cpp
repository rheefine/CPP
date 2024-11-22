#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main () {
	{
		std::cout << "ClapTrap" << std::endl << std::endl;
		ClapTrap clap("A");
		clap.attack("target1");
		clap.takeDamage(5);
		clap.beRepaired(3);
	}
	{
		std::cout << "FragTrap" << std::endl << std::endl;
		FragTrap frag("B");
		frag.attack("target2");
		frag.takeDamage(5);
		frag.beRepaired(3);
		frag.highFivesGuys();
	}
}
