#include <iostream>
#include "Serializer.hpp"

int main() {
	Data* originalData = new Data;
	originalData->name = "Test Data";
	originalData->value = 42;
	originalData->price = 3.14;

	// 원본 데이터 출력
	std::cout << "Original Data:" << std::endl;
	std::cout << "Address: " << originalData << std::endl;
	std::cout << "Name: " << originalData->name << std::endl;
	std::cout << "Value: " << originalData->value << std::endl;
	std::cout << "Price: " << originalData->price << std::endl;
	std::cout << std::endl;

	// 직렬화
	uintptr_t serialized = Serializer::serialize(originalData);
	std::cout << "Serialized value (uintptr_t): " << serialized << std::endl;
	std::cout << std::endl;

	// 역직렬화
	Data* deserialized = Serializer::deserialize(serialized);

	// 역직렬화된 데이터 출력
	std::cout << "Deserialized Data:" << std::endl;
	std::cout << "Address: " << deserialized << std::endl;
	std::cout << "Name: " << deserialized->name << std::endl;
	std::cout << "Value: " << deserialized->value << std::endl;
	std::cout << "Price: " << deserialized->price << std::endl;
	std::cout << std::endl;

	// 포인터 비교
	std::cout << "Pointer comparison:" << std::endl;
	std::cout << "Original  : " << originalData << std::endl;
	std::cout << "Serialized: " << reinterpret_cast<void*>(serialized) << std::endl;
	std::cout << "Deserialized: " << deserialized << std::endl;

	delete originalData;
	return 0;
}
