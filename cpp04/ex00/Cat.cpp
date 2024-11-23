#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat Default constructor called" << std::endl << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "Cat Copy constructor called" << std::endl << std::endl;
	*this = other;
}

Cat::~Cat() {
	std::cout << "Cat Destructor called" << std::endl << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat Copy Assignation operator called" << std::endl << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

void Cat::makeSound() const {
	std::cout << "ya-ong" << std::endl << std::endl;
}
