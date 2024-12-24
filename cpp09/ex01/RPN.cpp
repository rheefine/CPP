#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& other) : numbers(other.numbers) {}

RPN& RPN::operator=(const RPN& other) {
	if (this != &other) {
		numbers = other.numbers;
	}
	return *this;
}

bool RPN::isOperator(const char c) const {
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

void RPN::performOperation(const char op) {
	if (numbers.size() < 2) {
		std::cout << "Error" << std::endl;
		throw std::exception();
	}

	int b = numbers.top();
	numbers.pop();
	int a = numbers.top();
	numbers.pop();

	switch (op) {
		case '+':
			numbers.push(a + b);
			break;
		case '-':
			numbers.push(a - b);
			break;
		case '*':
			numbers.push(a * b);
			break;
		case '/':
			if (b == 0) {
				std::cout << "Error" << std::endl;
				throw std::exception();
			}
			numbers.push(a / b);
			break;
	}
}

void RPN::calculate(const std::string& expression) {
	for (std::string::const_iterator it = expression.begin(); it != expression.end(); ++it) {
		if (*it == ' ')
			continue;

		if (isdigit(*it)) {
			numbers.push(*it - '0');
		}
		else if (isOperator(*it)) {
			performOperation(*it);
		}
		else {
			std::cout << "Error" << std::endl;
			throw std::exception();
		}
	}

	if (numbers.size() != 1) {
		std::cout << "Error" << std::endl;
		throw std::exception();
	}

	std::cout << numbers.top() << std::endl;
	numbers.pop();
}
