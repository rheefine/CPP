#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug() {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info() {
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl
    << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning() {
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl
    << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error() {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(const std::string &level) {
	int i;

	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*fptr[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	i = 0;
	while (i < 4) {
		if (level == levels[i]) {
			(this->*fptr[i])();
			return;
		}
		i++;
	}
	std::cout << "Invalid Level." << std::endl;
}
