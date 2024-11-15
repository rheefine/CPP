#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "main.hpp"

class Contact {
	public:
		Contact();

		void setFirstName(std::string firstName);
		void setLastName(std::string lastName);
		void setNickName(std::string nickname);
		void setPhoneNumber(std::string phoneNumber);
		void setDarkestSecret(std::string darkestSecret);
		std::string getFirstName();
		std::string getLastName();
		std::string getNickName();
		std::string getPhoneNumber();
		std::string getDarkestSecret();

	private:
		void validateNotEmpty(const std::string &str);
		void validateName(const std::string &name);
		void validatePhoneNumber(const std::string &phoneNumber);

		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _phoneNumber;
		std::string _darkestSecret;
};


#endif
