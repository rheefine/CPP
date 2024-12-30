#include "PmergeMe.hpp"
#include <sys/time.h>
#include <iomanip>
#include <cstdlib>

double calculateTimeDiff(const struct timeval& start, const struct timeval& end) {
	return (end.tv_sec - start.tv_sec) * 1000000.0 +
		(end.tv_usec - start.tv_usec);
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cerr << "Error: No numbers provided." << std::endl;
		return 1;
	}

	std::vector<int> original;

	// Parse and validate input
	for (int i = 1; i < argc; i++) {
		char* endptr;
		long num = std::strtol(argv[i], &endptr, 10);

		if (*endptr != '\0' || num <= 0 || num > INT_MAX) {
			std::cerr << "Error: Invalid input '" << argv[i] << "'" << std::endl;
			return 1;
		}
		original.push_back(static_cast<int>(num));
	}

	// Print before sorting
	PmergeMe firstSorter;
	for (std::vector<int>::iterator it = original.begin(); it != original.end(); ++it) {
		firstSorter.addNumber(*it);
	}
	std::cout << "Before: ";
	firstSorter.printNumbers();

	struct timeval start, end;
	gettimeofday(&start, NULL);

	// 실제 정렬 수행
	PmergeMe sorter;
	for (std::vector<int>::iterator it = original.begin(); it != original.end(); ++it) {
		sorter.addNumber(*it);
	}
	sorter.sort();

	gettimeofday(&end, NULL);

	// Print after sorting
	std::cout << "After:  ";
	sorter.printNumbers();

	// Calculate and print time
	double duration = calculateTimeDiff(start, end);
	std::cout << "Time to process a range of " << argc - 1
			<< " elements with std::vector : "
			<< std::fixed << duration << " us" << std::endl;

	return 0;
}
