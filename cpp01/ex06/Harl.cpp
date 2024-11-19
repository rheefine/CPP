#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug() {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info() {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl
    << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning() {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl
    << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error() {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

int Harl::getLevelIndex(const std::string &level) {
	if (level == "DEBUG") return 0;
	if (level == "INFO") return 1;
	if (level == "WARNING") return 2;
	if (level == "ERROR") return 3;
	return 4;
}

void Harl::complain(const std::string &level) {
	int intLevel = getLevelIndex(level);

	switch (intLevel) {
		case 0:
			debug();
			// FALLTHROUGH
		case 1:
			info();
			// FALLTHROUGH
		case 2:
			warning();
			// FALLTHROUGH
		case 3:
			error();
			break;
		default:
			std::cout << "Invalid Arguement." << std::endl;
	}
}
