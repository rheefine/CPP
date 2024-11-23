#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	public :
		Cat();
		Cat(const Cat& other);

		~Cat();

		Cat& operator=(const Cat& other);

		void makeSound() const;
		Brain* getBrain() const;

	private :
		Brain* brain;

};

#endif
