#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

/*
#include <cstdlib>

void checkleak() {
	system("leaks ex01");
}
*/

int main() {
//	atexit(checkleak);

	std::cout << "=== Base Animal Test ===" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;

	std::cout << "\n=== Array of Animals Test ===" << std::endl;
	const Animal* animals[4];
	for (int k = 0; k < 4; k++) {
		if (k % 2 == 0)
			animals[k] = new Dog();
		else
			animals[k] = new Cat();
	}

	for (int i = 0; i < 4; i++) {
		std::cout << "Animal " << i << " makes sound: ";
		animals[i]->makeSound();
	}

	for (int i = 0; i < 4; i++) {
		delete animals[i];
	}

	std::cout << "\n=== Brain Test ===" << std::endl;
	const Cat* cat = new Cat();
	const Dog* dog = new Dog();

	cat->getBrain()->setIdea(0, "I am a cat");
	dog->getBrain()->setIdea(0, "I am a dog");

	std::cout << "Cat's idea: " << cat->getBrain()->getIdea(0) << std::endl;
	std::cout << "Dog's idea: " << dog->getBrain()->getIdea(0) << std::endl;

	delete cat;
	delete dog;

	std::cout << "\n=== Deep Copy Constructor Test ===" << std::endl;
	Cat* original = new Cat();
	original->getBrain()->setIdea(0, "Original thought");

	Cat* copy = new Cat(*original);
	copy->getBrain()->setIdea(0, "New thought");

	std::cout << "Original: " << original->getBrain()->getIdea(0) << std::endl;
	std::cout << "Copy: " << copy->getBrain()->getIdea(0) << std::endl;

	delete original;
	delete copy;

	std::cout << "\n=== Copy Assignment Operator Test ===" << std::endl;
	Cat* cat1 = new Cat();
	Cat* cat2 = new Cat();

	cat1->getBrain()->setIdea(0, "Cat1's original idea");
	cat2->getBrain()->setIdea(0, "Cat2's original idea");

	std::cout << "Before assignment:" << std::endl;
	std::cout << "Cat1: " << cat1->getBrain()->getIdea(0) << std::endl;
	std::cout << "Cat2: " << cat2->getBrain()->getIdea(0) << std::endl;

	*cat2 = *cat1;
	cat2->getBrain()->setIdea(0, "Cat2's new idea");

	std::cout << "\nAfter assignment and modification:" << std::endl;
	std::cout << "Cat1: " << cat1->getBrain()->getIdea(0) << std::endl;
	std::cout << "Cat2: " << cat2->getBrain()->getIdea(0) << std::endl;

	delete cat1;
	delete cat2;

	return 0;
}
