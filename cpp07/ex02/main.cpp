#include <iostream>
#include "Array.hpp"
#define MAX_VAL 750

int custom_test() {
	// 기본 생성자
	Array<int> empty;
	std::cout << "Empty array size: " << empty.size() << std::endl;

	// n 크기 생성자
	Array<int> numbers(5);
	std::cout << "Number array size: " << numbers.size() << std::endl;

	// 값 할당
	for (unsigned int i = 0; i < numbers.size(); i++) {
		numbers[i] = i * 2;
	}

	// 값 출력
	std::cout << "Numbers array: ";
	for (unsigned int i = 0; i < numbers.size(); i++) {
		std::cout << numbers[i] << " ";
	}
	std::cout << std::endl;

	// 복사 생성자
	Array<int> copy(numbers);
	std::cout << "Copy array: ";
	for (unsigned int i = 0; i < copy.size(); i++) {
		std::cout << copy[i] << " ";
	}
	std::cout << std::endl;

	// 원본 배열 수정
	numbers[2] = 100;

	// 복사본이 영향받지 않는지 확인
	std::cout << "Original array: ";
	for (unsigned int i = 0; i < numbers.size(); i++) {
		std::cout << numbers[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Copy array: ";
	for (unsigned int i = 0; i < copy.size(); i++) {
		std::cout << copy[i] << " ";
	}
	std::cout << std::endl;

	// 문자열 배열
	Array<std::string> strings(3);
	strings[0] = "Hello";
	strings[1] = "World";
	strings[2] = "!";

	std::cout << "String array contents: ";
	for (unsigned int i = 0; i < strings.size(); i++) {
		std::cout << strings[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}

int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;//

	std::cout << std::endl;

	custom_test();
	return 0;
}
