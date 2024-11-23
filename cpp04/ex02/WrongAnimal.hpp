#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal& other);

		~WrongAnimal();

		WrongAnimal& operator=(const WrongAnimal& other);

		void makeSound() const;
		std::string getType() const;

	protected:
		std::string _type;

};

#endif
