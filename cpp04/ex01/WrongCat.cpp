#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "WrongCat Default constructor called" << std::endl << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	std::cout << "WrongCat Copy constructor called" << std::endl << std::endl;
	*this = other;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat Destructor called" << std::endl << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	std::cout << "WrongCat Assignation operator called" << std::endl << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << "wrong yaong" << std::endl << std::endl;
}
