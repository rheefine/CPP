#include "RPN.hpp"

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " \"expression\"" << std::endl;
		return 1;
	}

	RPN calculator;
	try {
		calculator.calculate(argv[1]);
	}
	catch (const std::exception& e) {
		return 1;
	}

	return 0;
}
