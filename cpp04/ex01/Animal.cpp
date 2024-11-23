#include "Animal.hpp"

Animal::Animal() : _type("default") {
	std::cout << "Animal default constructor called" << std::endl << std::endl;
}

Animal::Animal(std::string type) : _type(type) {
	std::cout << "Animal " << type << " constructor called" << std::endl << std::endl;
}

Animal::Animal(const Animal& src) {
	std::cout << "Animal Copy constructor called" << std::endl << std::endl;
	*this = src;
}

Animal::~Animal() {
	std::cout << "Animal Destructor called" << std::endl << std::endl;
}

Animal& Animal::operator=(const Animal& src) {
	std::cout << "Animal Copy Assignation operator called" << std::endl << std::endl;
	if (this != &src)
		_type = src._type;
	return *this;
}

void Animal::makeSound() const {
	std::cout << "Animal sound" << std::endl << std::endl;
}

std::string Animal::getType() const {
	return _type;
}
