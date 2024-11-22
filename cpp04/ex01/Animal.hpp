#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal& other);

		virtual ~Animal();

		Animal& operator=(const Animal& other);

		virtual void makeSound() const;
		std::string getType() const;

	protected:
		std::string _type;

};

#endif
