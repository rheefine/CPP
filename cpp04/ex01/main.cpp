#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;

	const Animal* animals[4];
	for (int k = 0; k < 4; k++) {
		if (k % 2 == 0)
			animals[k] = new Dog();
		else
			animals[k] = new Cat();
	// animals[k].brain->setIdea(0, "I am an animal"); // ERROR
	}

	for (int i = 0; i < 4; i++) {
		animals[i]->makeSound();
	}

	const Cat* cat = new Cat();
	const Dog* dog = new Dog();

	cat->getBrain()->setIdea(0, "I am a cat");
	dog->getBrain()->setIdea(0, "I am a dog");

	cat->getBrain()->getIdea(0);
	dog->getBrain()->getIdea(0);

	return 0;
}
