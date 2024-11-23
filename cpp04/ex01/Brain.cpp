#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain Default constructor called" << std::endl << std::endl;
}

Brain::Brain(const Brain& other) {
	std::cout << "Brain Copy constructor called" << std::endl << std::endl;
	for (int i = 0; i < 100; i++) {
		_ideas[i] = other._ideas[i];
	}
}

Brain::~Brain() {
	std::cout << "Brain Destructor called" << std::endl << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
	std::cout << "Brain Copy Assignation operator called" << std::endl << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; i++)
			_ideas[i] = other._ideas[i];
	}
	return *this;
}

void Brain::setIdea(int i, std::string idea) {
	if (i < 0 || i >= 100) return;
	_ideas[i] = idea;
}

std::string Brain::getIdea(int i) const {
	if (i < 0 || i >= 100) return "Invalid index";
	return _ideas[i];
}
