#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), brain(new Brain()) {
	std::cout << "Dog Default constructor called" << std::endl << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*other.brain)) {
	std::cout << "Dog Copy constructor called" << std::endl << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog Destructor called" << std::endl << std::endl;
	delete brain;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog Copy Assignation operator called" << std::endl << std::endl;
	if (this != &other) {
		_type = other._type;
		delete brain;
		brain = new Brain(*other.brain);
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << "mung" << std::endl << std::endl;
}

Brain* Dog::getBrain() const {
	return brain;
}
