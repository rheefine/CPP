#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain Default constructor called" << std::endl << std::endl;
}

Brain::Brain(const Brain& other) {
	std::cout << "Brain Copy constructor called" << std::endl << std::endl;
	*this = other;
}

Brain::~Brain() {
	std::cout << "Brain Destructor called" << std::endl << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
	std::cout << "Brain Assignation operator called" << std::endl << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	}
	return *this;
}

void Brain::setIdea(int i, std::string idea) {
	ideas[i] = idea;
}

std::string Brain::getIdea(int i) const {
	return ideas[i];
}
