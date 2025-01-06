#include "PmergeMe.hpp"
#include "PmergeMeDeq.hpp"
#include <sys/time.h>
#include <iomanip>
#include <cstdlib>
#include <iostream>

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
	PmergeMe sortVec;
	PmergeMeDeq sortDeq;

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

	// Add numbers to both containers before timing
	for (std::vector<int>::iterator it = original.begin(); it != original.end(); ++it) {
		sortVec.addNumber(*it);
		sortDeq.addNumber(*it);
	}

	std::cout << "Before: ";
	sortVec.printNumbers();

	// Vector timing
	struct timeval startVec, endVec;
	gettimeofday(&startVec, NULL);
	sortVec.sort();
	gettimeofday(&endVec, NULL);

	std::cout << "After(vector): ";
	sortVec.printResult();

	double durationVec = calculateTimeDiff(startVec, endVec);

	// Deque timing
	struct timeval startDeq, endDeq;
	gettimeofday(&startDeq, NULL);
	sortDeq.sort();
	gettimeofday(&endDeq, NULL);

	std::cout << "After(deque): ";
	sortDeq.printResult();

	double durationDeq = calculateTimeDiff(startDeq, endDeq);


	std::cout << "Time to process a range of " << argc - 1
			<< " elements with std::vector : "
			<< std::fixed << durationVec << " us" << std::endl;

	std::cout << "Time to process a range of " << argc - 1
			<< " elements with std::deque : "
			<< std::fixed << durationDeq << " us" << std::endl;

	return 0;
}
