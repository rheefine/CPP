#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include "Node.hpp"
#include <vector>
#include <iostream>

class PmergeMe {
public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	void addNumber(int num);
	void sort();
	void printNumbers() const;
	void printResult() const;

private:
	std::vector<Node> numbers;
	std::vector<Node> result;
	std::vector<int> sequence;

	std::vector<int> generateJacobsthalNumbers(size_t n);
	void binaryInsert(Node element);
	void recursiveSort(std::vector<Node>& nodes);
};

#endif
