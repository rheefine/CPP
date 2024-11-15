#include "Zombie.hpp"

Zombie::Zombie() {
	std::cout << "Anonymous Zombie spawned." << std::endl<< std::endl;
}

Zombie::Zombie(std::string name) {
	_name = name;
	std::cout << _name << ": spawned." << std::endl<< std::endl;
}

Zombie::~Zombie() {
	std::cout << _name << ": died." << std::endl<< std::endl;
}

void Zombie::announce() {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl<< std::endl;
}

void Zombie::setName(std::string name) {
	_name = name;
	std::cout << "Zombie name set to " << _name << std::endl<< std::endl;
}
