#include "HumanB.hpp"

HumanB::HumanB(const std::string name) : name(name) {}

void HumanB::setWeapon(Weapon& weapon) {
	this->weapon = &weapon;
}

void HumanB::attack() {
	std::cout << this->name << " attacks with " << this->weapon->getType() << std::endl << std::endl;
}
