#include "main.hpp"

int main() {
	int N = 3;

	Zombie* horde = zombieHorde(N, "Horde Zombie");

	for (int i = 0; i < N; i++) {
		horde[i].announce();
	}

	delete[] horde;

	return 0;
}
