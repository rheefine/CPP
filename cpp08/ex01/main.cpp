#include <iostream>
#include "Span.hpp"
#include <vector>
#include <deque>
#include <cstdlib>
#include <ctime>

void error_test() {
	Span sp = Span(5);
	try {
		std::cout << sp.shortestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << sp.longestSpan() << std::endl;
	} catch	(std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	sp.addNumber(6);
	try {
		std::cout << sp.shortestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << sp.longestSpan() << std::endl;
	} catch	(std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

void large_test () {
	srand(time(NULL));
	Span sp2 = Span(10000);
	std::deque<int> dq;
	for (size_t i = 0; i < 10000; i++) {
		dq.push_back(rand());
	}
	sp2.addNumbers(dq.begin(), dq.end());
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;
}

int main() {
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	error_test();
	large_test();
	return 0;
}
