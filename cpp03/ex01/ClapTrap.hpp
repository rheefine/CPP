#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
	public:
		ClapTrap();
		virtual ~ClapTrap();
		ClapTrap(const ClapTrap &claptrap);
		ClapTrap &operator=(const ClapTrap &copy);

		ClapTrap(std::string name);

		virtual void attack(std::string const &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	protected:
		std::string _name;
		unsigned int _hitPoints;
		unsigned int _energyPoints;
		unsigned int _attackDamage;

		bool isDead();
		bool isEnergy();
};

#endif
