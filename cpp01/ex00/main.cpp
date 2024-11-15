#include "main.hpp"

int main() {

	Zombie zombie = Zombie("foo");

	zombie.announce();

	Zombie* heapZombie = newZombie("Heap Zombie");

	heapZombie->announce();

	randomChump("Stack Zombie");

	delete heapZombie;

	return 0;
}
