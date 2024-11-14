#include <iostream>
#include <cctype>

int main(int ac, char **av) {
	int j;
	char c;

	if (ac == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else {
		for (int i = 1; i < ac; i++) {
			j = 0;
			while (av[i][j]) {
				c = av[i][j];
				std::cout << (char)toupper(c);
				j++;
			}
		}
	}
	std::cout << std::endl;
	return 0;
}
