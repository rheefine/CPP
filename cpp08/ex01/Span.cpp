#include "Span.hpp"

Span::Span() : _n(0) {}

Span::Span(unsigned int n) : _n(n) {}

Span::Span(const Span& other) : _n(other._n), _numbers(other._numbers) {}

Span::~Span() {}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		_n = other._n;
		_numbers = other._numbers;
	}
	return *this;
}

void Span::addNumber(int num) {
	if (_numbers.size() >= _n) {
		throw std::exception();
	}
	_numbers.push_back(num);
}

int Span::shortestSpan() {
	if (_numbers.size() <= 1) {
		throw std::exception();
	}
	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());
	int min = sorted[1] - sorted[0];
	for (size_t i = 2; i < sorted.size(); i++) {
		int diff = sorted[i] - sorted[i - 1];
		if (diff < min) {
			min = diff;
		}
	}
	return min;
}

int Span::longestSpan() {
	if (_numbers.size() <= 1) {
		throw std::exception();
	}
	int min = *std::min_element(_numbers.begin(), _numbers.end());
	int max = *std::max_element(_numbers.begin(), _numbers.end());
	return max - min;
}
