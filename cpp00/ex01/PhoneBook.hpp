#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "main.hpp"
# include "Contact.hpp"

class PhoneBook {
	public:
		PhoneBook();
		void add();
		void search();

	private:
		Contact _contacts[8];
		int _count;

		void setContact(Contact &contact);
		std::string readInfo(const std::string &msg);

		void displayPhoneBook();
		void displayContact(int index);
		std::string formatColumn(std::string str);

		int readIndex();
		int validateIndex(const std::string &input);
};

#endif
