#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog Default constructor called" << std::endl << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Dog Copy constructor called" << std::endl << std::endl;

	*this = other;
}

Dog::~Dog() {
	std::cout << "Dog Destructor called" << std::endl << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog Assignation operator called" << std::endl << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

void Dog::makeSound() const {
	std::cout << "mung" << std::endl << std::endl;
}
