#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <exception>
#include <iostream>

class RPN {
private:
	std::stack<int> numbers;

	bool isOperator(const char c) const;
	void performOperation(const char op);

public:
	RPN();
	~RPN();
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);

	void calculate(const std::string& expression);
};

#endif
