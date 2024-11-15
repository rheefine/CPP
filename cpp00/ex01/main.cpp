#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook phoneBook;
	std::string cmd;

	while (true) {
		try {
			std::cout << "------------- Phone Book -------------" << std::endl;
			std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl << std::endl;
			std::cout << "Enter a command: ";
			std::getline(std::cin, cmd);
			std::cout << std::endl;
			if (cmd == "ADD") {
				phoneBook.add();
			}
			else if (cmd == "SEARCH") {
				phoneBook.search();
			}
			else if (cmd == "EXIT") {
				std::cout << "Exit program." << std::endl;
				break ;
			}
			else if (std::cin.eof())
				throw std::exception();
			else
				std::cout << "Invalid command. Please try again." << std::endl;
		} catch (std::exception &e) {
			std::cin.clear();
			clearerr(stdin);
			std::cout << std::endl;
		}
	}
	return (0);
}
