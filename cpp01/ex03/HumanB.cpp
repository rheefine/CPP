#include "HumanB.hpp"

HumanB::HumanB(const std::string name) : name(name), weapon(NULL) {}

void HumanB::setWeapon(Weapon& weapon) {
	this->weapon = &weapon;
}

void HumanB::attack() {
	if (this->weapon == NULL) {
		std::cout << this->name << " has no weapon" << std::endl << std::endl;
		return;
	}
	std::cout << this->name << " attacks with " << this->weapon->getType() << std::endl << std::endl;
}
