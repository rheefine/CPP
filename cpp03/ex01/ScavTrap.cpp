#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "ScavTrap Default constructor called" << std::endl << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap Destructor called" << std::endl << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavtrap) : ClapTrap(scavtrap) {
	std::cout << "ScavTrap Copy constructor called" << std::endl << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy) {
	std::cout << "ScavTrap Copy assignment operator called" << std::endl << std::endl;
	if (this != &copy) {
		ClapTrap::operator=(copy);
	}
	return *this;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap " << name << " constructor called" << std::endl << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

void ScavTrap::attack(const std::string& target) {
	if (isDead()) return;
	if (isEnergy()) return;
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage! " << std::endl << std::endl;
	_energyPoints -= 1;
};

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << _name << " has entered in Gate keeper mode" << std::endl << std::endl;
}
