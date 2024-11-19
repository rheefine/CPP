#include "Harl.hpp"

int getLevelIndex(const std::string &level) {
	if (level == "DEBUG") return 0;
	if (level == "INFO") return 1;
	if (level == "WARNING") return 2;
	if (level == "ERROR") return 3;
	return 4;
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cout << "Usage: ./harlFilter <level>" << std::endl;
		return 1;
	}

	Harl harl;
	harl.complain(argv[1]);
	return 0;
}
