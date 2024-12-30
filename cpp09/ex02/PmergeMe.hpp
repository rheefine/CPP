#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <iostream>
#include <utility> // for std::pair
#include <algorithm> // for std::lower_bound

class PmergeMe {
public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	void addNumber(int num);
	void sort();
	void printNumbers() const;
	const std::vector<int>& getNumbers() const;

private:
	std::vector<int> numbers;

	void recursiveSort(std::vector<std::pair<int, int> >& pairs);
	void binaryInsert(std::vector<int>& chain, int element);
};

#endif
