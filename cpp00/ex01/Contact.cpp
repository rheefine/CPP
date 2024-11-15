#include "Contact.hpp"

Contact::Contact() {
}

void Contact::setFirstName(std::string firstName) {
	validateName(firstName);
	_firstName = firstName;
}

void Contact::setLastName(std::string lastName) {
	validateName(lastName);
	_lastName = lastName;
}

void Contact::setNickName(std::string nickName) {
	validateNotEmpty(nickName);
	_nickName = nickName;
}

void Contact::setPhoneNumber(std::string phoneNumber) {
	validatePhoneNumber(phoneNumber);
	_phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(std::string darkestSecret) {
	validateNotEmpty(darkestSecret);
	_darkestSecret = darkestSecret;
}

std::string Contact::getFirstName() {
	return _firstName;
}

std::string Contact::getLastName() {
	return _lastName;
}

std::string Contact::getNickName() {
	return _nickName;
}

std::string Contact::getPhoneNumber() {
	return _phoneNumber;
}

std::string Contact::getDarkestSecret() {
	return _darkestSecret;
}


void Contact::validateNotEmpty(const std::string &str) {
	if (str.empty()) {
		std::cout << "Input cannot be empty" << std::endl;
		throw std::exception();
	}

	bool onlySpaces = true;
	for(std::string::size_type i = 0; i < str.length(); i++) {
		if (!isspace(str[i])) {
			onlySpaces = false;
			break;
		}
	}

	if (onlySpaces) {
		std::cout << "Input cannot contain only spaces" << std::endl;
		throw std::exception();
	}
}

void Contact::validateName(const std::string &str) {
	validateNotEmpty(str);
	for(std::string::size_type i = 0; i < str.length(); i++) {
		if(!isalpha(str[i])) {
			std::cout << "Name must contain only alphabets" << std::endl;
			throw std::exception();
		}
	}
}

void Contact::validatePhoneNumber(const std::string &phoneNumber) {
	validateNotEmpty(phoneNumber);
	for(std::string::size_type i = 0; i < phoneNumber.length(); i++) {
		if(!isdigit(phoneNumber[i])) {
			std::cout << "Phone number must contain only digits" << std::endl;
			throw std::exception();
		}
	}
}
