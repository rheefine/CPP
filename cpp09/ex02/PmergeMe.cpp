#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : numbers(other.numbers) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		numbers = other.numbers;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::addNumber(int num) {
	numbers.push_back(num);
}

// 대표 원소들을 정렬하는 재귀 함수
void PmergeMe::recursiveSort(std::vector<std::pair<int, int> >& pairs) {
	if (pairs.size() <= 1) return;

	// 대표 원소들끼리 재귀적으로 정렬
	std::vector<std::pair<int, int> > recursivePairs;
	for (std::vector<std::pair<int, int> >::size_type i = 0; i < pairs.size() - 1; i += 2) {
		if (pairs[i].first < pairs[i + 1].first)
			std::swap(pairs[i], pairs[i + 1]);
		recursivePairs.push_back(pairs[i]);
	}

	// 홀수 개일 경우 마지막 쌍 처리
	if (pairs.size() % 2 == 1)
		recursivePairs.push_back(pairs[pairs.size() - 1]);

	// 재귀적으로 대표 원소들 정렬
	recursiveSort(recursivePairs);

	// 정렬된 대표 원소들을 pairs에 반영
	for (std::vector<std::pair<int, int> >::size_type i = 0; i < recursivePairs.size(); ++i)
		pairs[i * 2] = recursivePairs[i];
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
		}
		else {
			end = mid - 1;
		}
	}
	chain.insert(chain.begin() + start, element);
}

void PmergeMe::sort() {
	if (numbers.size() <= 1) return;

	// 1. 원소들을 쌍으로 묶기
	std::vector<std::pair<int, int> > pairs;
	bool hasOdd = false;
	int oddElement;

	for (std::vector<int>::size_type i = 0; i < numbers.size() - 1; i += 2) {
		int first = numbers[i];
		int second = numbers[i + 1];
		if (first < second)
			std::swap(first, second);
		pairs.push_back(std::make_pair(first, second));
	}

	if (numbers.size() % 2) {
		hasOdd = true;
		oddElement = numbers[numbers.size() - 1];
	}

	// 2. 대표 원소들을 정렬
	recursiveSort(pairs);

	// 3. 정렬된 체인 생성 (대표 원소들)
	std::vector<int> sortedChain;
	for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
		sortedChain.insert(sortedChain.begin(), it->first);
	}

	// 4. 나머지 원소들을 이진 삽입
	for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
		binaryInsert(sortedChain, it->second);

	// 홀수 원소가 있다면 삽입
	if (hasOdd)
		binaryInsert(sortedChain, oddElement);

	// 결과를 원래 벡터에 복사
	numbers = sortedChain;
}

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

// 1. 이진 탐색 구현해보기
// 2. 야콥스탈 수열 배열 만들고 해당 순서에 따라 정렬하기 ex: [1, 3, 2, 5, 4, 11, 10, 9, 8, 7, 6, 21, 20, 19, ...]

