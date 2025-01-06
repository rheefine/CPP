#include "PmergeMeDeq.hpp"

PmergeMeDeq::PmergeMeDeq() {}

PmergeMeDeq::PmergeMeDeq(const PmergeMeDeq& other) {
	numbers = other.numbers;
	result = other.result;
}

PmergeMeDeq& PmergeMeDeq::operator=(const PmergeMeDeq& other) {
	if (this == &other)
		return *this;
	numbers = other.numbers;
	result = other.result;
	return *this;
}

PmergeMeDeq::~PmergeMeDeq() {}

void PmergeMeDeq::addNumber(int num) {
	numbers.push_back(Node(num));
}

void PmergeMeDeq::printNumbers() const {
	for (size_t i = 0; i < numbers.size(); i++) {
		std::cout << numbers[i].getMax() << " ";
	}
	std::cout << std::endl;
}

void PmergeMeDeq::printResult() const {
	for (size_t i = 0; i < result.size(); i++) {
		std::cout << result[i].getMax() << " ";
	}
	std::cout << std::endl;
}

std::deque<int> PmergeMeDeq::generateJacobsthalNumbers(size_t n) {
	std::deque<int> sequence;
	if (n == 0)
		return sequence;
	if (n == 1) {
		sequence.push_back(1);
		return sequence;
	}

	std::deque<int> jacobsthal;
	jacobsthal.push_back(1);
	jacobsthal.push_back(3);

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

	for (size_t i = sequence.size(); i < n; n--) {
		sequence.push_back(n);
	}

	return sequence;
}

void PmergeMeDeq::binaryInsert(Node element) {
	if (result.empty()) {
		result.push_back(element);
		return;
	}
	int start = 0;
	int end = result.size() - 1;
	if (element <= result[0]) {
		result.push_front(element);
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

void PmergeMeDeq::sort() {
	if (numbers.size() <= 1)
		return;

	recursiveSort(numbers);
}

void PmergeMeDeq::recursiveSort(std::deque<Node>& nodes) {
	if (nodes.size() == 1) {
		result.push_back(nodes[0]);
		return;
	}

	std::deque<Node> newNodes;
	Node* lastNode = nullptr;

	if (nodes.size() % 2 != 0) {
		lastNode = &nodes[nodes.size() - 1];
	}

	for (size_t i = 0; i < (nodes.size() / 2) * 2; i += 2)
		newNodes.push_back(Node(&nodes[i], &nodes[i + 1]));

	recursiveSort(newNodes);

	std::deque<Node> mergedNodes;
	int result_size = result.size();
	for (int i = 0; i < result_size; i++)
		mergedNodes.push_back(*result[i].getMinNode());
	for (int i = 0; i < result_size; i++)
		result[i] = *result[i].getMaxNode();
	std::deque<int> sequence = generateJacobsthalNumbers(mergedNodes.size());
	for (size_t i = 0; i < mergedNodes.size(); i++)
		binaryInsert(mergedNodes[sequence[i] - 1]);

	if (lastNode != nullptr)
		binaryInsert(*lastNode);
}
