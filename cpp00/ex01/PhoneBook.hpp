#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "main.hpp"

class PhoneBook {
	private:
		Contact contacts[8];
		int count;

	public:
		PhoneBook();
		~PhoneBook();
		void add();
		void search();
};

#endif
