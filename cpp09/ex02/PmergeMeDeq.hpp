#ifndef PMERGEMEDEQ_HPP
#define PMERGEMEDEQ_HPP

#include "Node.hpp"
#include <deque>
#include <iostream>

class PmergeMeDeq {
public:
	PmergeMeDeq();
	PmergeMeDeq(const PmergeMeDeq& other);
	PmergeMeDeq& operator=(const PmergeMeDeq& other);
	~PmergeMeDeq();

	void addNumber(int num);
	void sort();
	void printNumbers() const;
	void printResult() const;

private:
	std::deque<Node> numbers;
	std::deque<Node> result;
	std::deque<int> sequence;

	std::deque<int> generateJacobsthalNumbers(size_t n);
	void binaryInsert(Node element);
	void recursiveSort(std::deque<Node>& nodes);
};

#endif
