#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main () {
	{
		std::cout << "ClapTrap" << std::endl << std::endl;
		ClapTrap clap("A");
		clap.attack("target1");
		clap.takeDamage(5);
		clap.beRepaired(3);
	}
	{
		std::cout << "ScavTrap" << std::endl << std::endl;
		ScavTrap scav("B");
		scav.attack("target2");
		scav.takeDamage(5);
		scav.beRepaired(3);
		scav.guardGate();
	}
}
