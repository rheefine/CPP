#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "FragTrap Default constructor called" << std::endl << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap Destructor called" << std::endl << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragtrap) : ClapTrap(fragtrap) {
	std::cout << "FragTrap Copy constructor called" << std::endl << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &copy) {
	std::cout << "FragTrap Copy assignment operator called" << std::endl << std::endl;
	if (this != &copy) {
		ClapTrap::operator=(copy);
	}
	return *this;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "FragTrap " << name << " constructor called" << std::endl << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

void FragTrap::attack(const std::string& target) {
	if (isDead()) return;
	if (isEnergy()) return;
	std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage! " << std::endl << std::endl;
	_energyPoints -= 1;
};

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << _name << " high fives guys!" << std::endl << std::endl;
};
