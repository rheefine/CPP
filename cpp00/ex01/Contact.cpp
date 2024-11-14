#include "Contact.hpp"

Contact::Contact() {
}

Contact::~Contact() {
}

void Contact::setFirstName(std::string firstName) {
	_firstName = firstName;
}

void Contact::setLastName(std::string lastName) {
	_lastName = lastName;
}

void Contact::setNickName(std::string nickName) {
	_nickName = nickName;
}

void Contact::setPhoneNumber(std::string phoneNumber) {
	for (size_t i = 0; i < phoneNumber.length(); i++) {
		if (!std::isdigit(phoneNumber[i])) {
			throw std::invalid_argument("Invalid phone number");
		}
	}
	_phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(std::string darkestSecret) {
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
