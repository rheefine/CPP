#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base* generate(void) {
	// 시드 초기화
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	int random = std::rand() % 3;

	switch (random) {
		case 0:
			std::cout << "Generated type A" << std::endl;
			return new A();
		case 1:
			std::cout << "Generated type B" << std::endl;
			return new B();
		case 2:
			std::cout << "Generated type C" << std::endl;
			return new C();
		default:
			return NULL;
	}
}

void identify(Base* p) {
	// dynamic_cast를 사용하여 실제 타입 확인
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void identify(Base& p) {
	// 참조자를 사용한 동적 캐스팅
	// dynamic_cast 실패 시 std::bad_cast 예외 발생
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	} catch (std::bad_cast&) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	} catch (std::bad_cast&) {}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	} catch (std::bad_cast&) {}

	std::cout << "Unknown type" << std::endl;
}

int main() {
	Base* ptr = generate();

	std::cout << "Identify using pointer: ";
	identify(ptr);

	std::cout << "Identify using reference: ";
	identify(*ptr);

	delete ptr;

	return 0;
}
