#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
	numbers = other.numbers;
	result = other.result;
}
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this == &other)
		return *this;
	numbers = other.numbers;
	result = other.result;
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::addNumber(int num) {
	numbers.push_back(Node(num));
}

void PmergeMe::printNumbers() const {
	for (size_t i = 0; i < numbers.size(); i++) {
		std::cout << numbers[i].getMax() << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printResult() const {
	for (size_t i = 0; i < result.size(); i++) {
		std::cout << result[i].getMax() << " ";
	}
	std::cout << std::endl;
}

std::vector<int> PmergeMe::generateJacobsthalNumbers(size_t n) {
	std::vector<int> sequence;
	if (n == 0)
		return sequence;
	if (n == 1) {
		sequence.push_back(1);
		return sequence;
	}

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

	return sequence;
}

void PmergeMe::binaryInsert(Node element) {
	if (result.empty()) {
		result.push_back(element);
		return;
	}
	int start = 0;
	int end = result.size() - 1;
	if (element <= result[0]) {
		result.insert(result.begin(), element);
		return;
	}
	if (element >= result[end]) {
		result.push_back(element);
		return;
	}
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (result[mid] < element) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	result.insert(result.begin() + start, element);
}

void PmergeMe::sort() {
	if (numbers.size() <= 1)
		return;

	recursiveSort(numbers);
}

void PmergeMe::recursiveSort(std::vector<Node>& nodes) {
	if (nodes.size() == 1) {
		result.push_back(nodes[0]);
		return;
	}

	std::vector<Node> newNodes;
	Node* lastNode = nullptr;

	// 홀수 개의 노드가 있다면 마지막 노드를 저장
	if (nodes.size() % 2 != 0) {
		lastNode = &nodes[nodes.size() - 1];
	}

	// 짝수 개만큼만 새 노드 생성
	for (size_t i = 0; i < (nodes.size() / 2) * 2; i += 2)
		newNodes.push_back(Node(&nodes[i], &nodes[i + 1]));

	recursiveSort(newNodes);

	std::vector<Node> mergedNodes;
	int result_size = result.size();
	for (int i = 0; i < result_size; i++)
		mergedNodes.push_back(*result[i].getMinNode());
	for (int i = 0; i < result_size; i++)
		result[i] = *result[i].getMaxNode();
	std::vector<int> sequence = generateJacobsthalNumbers(mergedNodes.size());
	for (size_t i = 0; i < mergedNodes.size(); i++)
		binaryInsert(mergedNodes[sequence[i] - 1]);

	// 재귀 과정의 홀수 노드 처리
	if (lastNode != nullptr)
		binaryInsert(*lastNode);
}
