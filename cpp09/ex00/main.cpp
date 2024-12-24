#include <iostream>
#include <map>
#include <algorithm>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Usage: ./btc <file>" << std::endl;
		return 1;
	}
	BitcoinExchange exchange(argv[1]);
	exchange.parseData();
	exchange.printResult();
	return 0;
}