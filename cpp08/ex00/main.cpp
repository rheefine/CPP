#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main() {
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	std::cout << "Test vector" << std::endl;
	try {
		std::vector<int>::iterator it = easyfind(vec, 3);
		std::cout << *it << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	try {
		std::vector<int>::iterator it = easyfind(vec, 6);
		std::cout << *it << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	lst.push_back(40);

	std::cout << "\nTest list" << std::endl;
	try {
		std::list<int>::iterator it = easyfind(lst, 20);
		std::cout << "Found value: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::deque<int> deq;
	deq.push_back(100);
	deq.push_back(200);
	deq.push_back(300);

	std::cout << "\nTest deque" << std::endl;
	try {
		std::deque<int>::iterator it = easyfind(deq, 400);
		std::cout << *it << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}
