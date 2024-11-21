#include "ClapTrap.hpp"

int main () {
	ClapTrap clap("A");

	clap.attack("target1");

	clap.takeDamage(5);

	clap.beRepaired(3);

	clap.beRepaired(1000);

	clap.takeDamage(1007);

	clap.attack("target2");

	clap.takeDamage(1);

	return 0;
}
