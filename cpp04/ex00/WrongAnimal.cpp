#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Not implemented") {
	std::cout << "WrongAnimal constructor called" << std::endl << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	std::cout << "WrongAnimal " << type << " constructor called" << std::endl << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src) {
	std::cout << "WrongAnimal Copy constructor called" << std::endl << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal Destructor called" << std::endl << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& src) {
	std::cout << "WrongAnimal Assignation operator called" << std::endl << std::endl;
	if (this != &src)
		_type = src._type;
	return *this;
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal sound" << std::endl << std::endl;
}

std::string WrongAnimal::getType() const {
	return _type;
}
