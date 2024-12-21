#include "MutantStack.hpp"
#include <list>
#include <iostream>

void test_reverse(MutantStack<int> mstack) {
	std::cout << "\n=== Test Reverse Iterator ===" << std::endl;

	std::cout << "Forward iteration: ";
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "Reverse iteration: ";
	for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void test_const(const MutantStack<int>& mstack) {
	std::cout << "\n=== Test Const Iterators ===" << std::endl;

	std::cout << "Const forward iteration: ";
	for (MutantStack<int>::const_iterator it = mstack.begin(); it != mstack.end(); ++it) {
		std::cout << *it << " ";
		// *it = 10;  // 컴파일 에러
	}
	std::cout << std::endl;

	std::cout << "Const reverse iteration: ";
	for (MutantStack<int>::const_reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it) {
		std::cout << *it << " ";
		// *it = 10;  // 컴파일 에러
	}
	std::cout << std::endl;
}


void test_list() {
	std::cout << "\n=== Compare List ===" << std::endl;
	std::list<int> lst;

	lst.push_back(5);
	lst.push_back(17);
	std::cout << lst.back() << std::endl;
	lst.pop_back();
	std::cout << lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);
	std::list<int>::iterator it = lst.begin();
	std::list<int>::iterator ite = lst.end();
	++it;
	--it;
	std::cout << "Elements: ";
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << std::endl;
}

void test_ms() {
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

int main()
{
	test_ms();
	test_list();

	MutantStack<int> mstack;
	for (int i = 1; i <= 5; ++i)
		mstack.push(i);
	test_reverse(mstack);
	test_const(mstack);
	return 0;
}
