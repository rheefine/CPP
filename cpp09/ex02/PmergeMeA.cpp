#include "PmergeMe.hpp"
/*
#include <algorithm>
#include <utility>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : numbers(other.numbers), sequence(other.sequence) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		numbers = other.numbers;
		sequence = other.sequence;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::printNumbers() const {
	for (std::vector<int>::const_iterator it = numbers.begin(); it != numbers.end(); ++it) {
		std::cout << *it;
		if (it + 1 != numbers.end())
			std::cout << " ";
	}
	std::cout << std::endl;
}

const std::vector<int>& PmergeMe::getNumbers() const {
	return numbers;
}

void PmergeMe::addNumber(int num) {
	numbers.push_back(num);
}

void PmergeMe::generateJacobsthalNumbers(size_t n) {
	if (n <= 1) return ;

	std::vector<int> jacobsthal;
	jacobsthal.push_back(1);
	jacobsthal.push_back(3);

	// Jacobsthal 수열: J(n) = J(n-1) + 2J(n-2)
	while (jacobsthal.back() < static_cast<int>(n)) {
		int next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
		jacobsthal.push_back(next);
	}

	sequence.push_back(jacobsthal[0]);
	for (size_t i = 1; i < jacobsthal.size() - 1; ++i) {
		int now = jacobsthal[i];
		while (now > jacobsthal[i - 1]) {
			sequence.push_back(now--);
		}
	}

	for (size_t i = sequence.size(); i < n ; n-- ) {
		sequence.push_back(n);
	}

}

void PmergeMe::binaryInsert(std::vector<int>& chain, int element) {
	if (chain.empty()) {
		chain.push_back(element);
		return;
	}

	int start = 0;
	int end = chain.size() - 1;

	if (element <= chain[0]) {
		chain.insert(chain.begin(), element);
		return;
	}
	if (element >= chain[end]) {
		chain.push_back(element);
		return;
	}

	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (chain[mid] < element) {
			start = mid + 1;
		} else {
			end = mid - 1;
		}
	}
	chain.insert(chain.begin() + start, element);
}

 */

void PmergeMe::mergeInsertSort(std::vector<int> devideNumbers) {
	if (devideNumbers.size() <= 1) return;

}

void PmergeMe::sort() {
	if (numbers.size() <= 1) return;

	generateJacobsthalNumbers(numbers.size());
}
