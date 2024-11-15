#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	_count = 0;
}

void PhoneBook::add() {
	Contact contact;

	try{
		setContact(contact);
	} catch (std::exception& e) {
		std::cin.clear();
		clearerr(stdin);
		return;
	}

	_contacts[_count % 8] = contact;
	_count++;
}

void PhoneBook::search() {
	displayPhoneBook();
	int index;

	try {
		index = readIndex();
	} catch (std::exception& e) {
		std::cin.clear();
		clearerr(stdin);
		return;
	}

	displayContact(index);
}

void PhoneBook::setContact(Contact &contact) {
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

std::string PhoneBook::readInfo(const std::string &msg) {
	std::string str;

	std::cout << msg;
	std::getline(std::cin, str);
	std::cout << std::endl;
	if (std::cin.eof()) throw std::exception();

	return str;
}

void PhoneBook::displayPhoneBook() {
	std::cout << "=============================================" << std::endl;
	std::cout << "|"
			<< std::setw(10) << "index" << "|"
			<< std::setw(10) << "first name" << "|"
			<< std::setw(10) << "last name" << "|"
			<< std::setw(10) << "nickname" << "|"
			<< std::endl;

	for (int i = 0; i < (_count > 8 ? 8 : _count); i++) {
		std::cout << "|"
				<< std::setw(10) << i << "|"
				<< std::setw(10) << formatColumn(_contacts[i].getFirstName()) << "|"
				<< std::setw(10) << formatColumn(_contacts[i].getLastName()) << "|"
				<< std::setw(10) << formatColumn(_contacts[i].getNickName()) << "|"
				<< std::endl;
	}
	std::cout << "=============================================" << std::endl << std::endl;
}

void PhoneBook::displayContact(int index) {
	std::cout << "index: " << index << std::endl;
	std::cout << "First name: " << _contacts[index].getFirstName() << std::endl;
	std::cout << "Last name: " << _contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << _contacts[index].getNickName() << std::endl;
	std::cout << "Phone number: " << _contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << _contacts[index].getDarkestSecret() << std::endl << std::endl;
}

std::string PhoneBook::formatColumn(std::string str) {
	if (str.length() > 10) {
		return str.substr(0, 9) + ".";
	}
	return str;
}

int PhoneBook::readIndex() {

	std::string input = readInfo("Enter index: ");

	int index = validateIndex(input);

	return index;
}


int PhoneBook::validateIndex(const std::string &input) {
	if (input.empty()) {
		std::cout << "Input cannot be empty" << std::endl;
		throw std::exception();
	}
	for (size_t i = 0; i < input.length(); i++) {
		if (!isdigit(input[i])) {
			std::cout << "Invalid index" << std::endl;
			throw std::exception();
		}
	}

	int index = std::atoi(input.c_str());

	bool isValid = (index >= 0) &&
				(_count < 8 ? index < _count : index < 8);

	if (!isValid) {
		std::cout << "Invalid index" << std::endl;
		throw std::exception();
	}

	return index;
}

