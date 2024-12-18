#include <iostream>
#include "iter.hpp"

// 테스트 함수 템플릿
template<typename T>
void print(T const & x) {
	std::cout << x << " ";
}

// 특정 타입을 위한 테스트 함수들
void multiply2(int const & n) {
	std::cout << n * 2 << " ";
}

void makeUpper(char const & c) {
	std::cout << (char)toupper(c) << " ";
}

int main(void) {

	int intArr[] = {1, 2, 3, 4, 5};
	std::cout << "Multiply integers by 2: ";
	iter(intArr, 5, multiply2);
	std::cout << std::endl;

	// 문자 배열 테스트
	char charArr[] = {'a', 'b', 'c', 'd', 'e'};
	std::cout << "Make uppercase: ";
	iter(charArr, 5, makeUpper);
	std::cout << std::endl;

	return 0;
}
