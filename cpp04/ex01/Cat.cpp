#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), brain(new Brain()) {
	std::cout << "Cat Default constructor called" << std::endl << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), brain(new Brain(*other.brain)) {
	std::cout << "Cat Copy constructor called" << std::endl << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat Destructor called" << std::endl << std::endl;
	delete brain;
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat Copy Assignation operator called" << std::endl << std::endl;
	if (this != &other) {
		_type = other._type;
		delete brain;
		brain = new Brain(*other.brain);
	}

	return *this;
}

void Cat::makeSound() const {
	std::cout << "ya-ong" << std::endl << std::endl;
}

Brain* Cat::getBrain() const {
	return brain;
}
