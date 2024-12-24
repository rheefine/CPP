#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}

	try {
		BitcoinExchange btc(argv[1]);
		btc.parseData();
		btc.printResult();
	}
	catch (const std::exception& e) {
		return 1;
	}

	return 0;
}
