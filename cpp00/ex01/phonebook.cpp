#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	count = 0;
}

PhoneBook::~PhoneBook() {
}

void PhoneBook::add() {
	Contact contact;

	std::string firstName = readInfo("Enter first name: ");
	contact.setFirstName(firstName);

	std::string lastName = readInfo("Enter last name: ");
	contact.setLastName(lastName);

	std::string nickName = readInfo("Enter nickname: ");
	contact.setNickName(nickName);

	std::string phoneNumber = readInfo("Enter phone number: ");
	contact.setPhoneNumber(phoneNumber);

	std::string darkestSecret = readInfo("Enter darkest secret: ");
	contact.setDarkestSecret(darkestSecret);

}

std::string readInfo(std::string msg) {
	std::string str;

	std::cout << msg;
	std::getline(std::cin, str);

	return str;
}

void readIndex() {
	std::string str;
	std::cout << "Enter index of the contact: ";
	std::getline(std::cin, str);
	if (std::cin.eof())
		throw std::exception();


}


int PhoneBook::search() {

}
