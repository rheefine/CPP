#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap Default constructor called" << std::endl << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap Destructor called" << std::endl << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap) {
	std::cout << "ClapTrap Copy constructor called" << std::endl << std::endl;
	*this = claptrap;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy) {
	std::cout << "ClapTrap Copy assignment operator called" << std::endl << std::endl;
	if (this != &copy) {
		_name = copy._name;
		_hitPoints = copy._hitPoints;
		_energyPoints = copy._energyPoints;
		_attackDamage = copy._attackDamage;
	}
	return *this;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap " << name << " constructor called" << std::endl << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (isDead()) return;
	if (isEnergy()) return;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage! " << std::endl << std::endl;
	_energyPoints -= 1;
};

void ClapTrap::takeDamage(unsigned int amount) {
	if (isDead()) return;
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage! " << std::endl << std::endl;
	if ( _hitPoints <= amount) {
		_hitPoints = 0;
		if (isDead()) return;
	}
	_hitPoints -= amount;
	return;
};

void ClapTrap::beRepaired(unsigned int amount) {
	if (isDead()) return;
	if (isEnergy()) return;
	std::cout << "ClapTrap " << _name << " has been repaired for " << amount << " hit points! " << std::endl << std::endl;
	_hitPoints += amount;
	return;
};

bool ClapTrap::isDead() {
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " is dead! " << std::endl << std::endl;
		return true;
	}
	return false;
};

bool ClapTrap::isEnergy() {
	if (_energyPoints == 0) {
		std::cout << "ClapTrap" << _name << "is out of energy!" << std::endl << std::endl;
		return true;
	}
	return false;
};
