#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <cstdlib>

template <typename T>
class Array {
private:
	T* arr;
	unsigned int arraySize;

public:
	Array() : arr(NULL), arraySize(0) {}

	Array(unsigned int n) : arraySize(n) {
		arr = new T[n]();
	}

	Array(const Array& other) : arr(NULL), arraySize(0) {
		*this = other;
	}

	~Array() {
		if (arr)
			delete[] arr;
	}

	Array& operator=(const Array& other) {
		if (this != &other) {
			if (arr)
				delete[] arr;
			arraySize = other.arraySize;
			arr = new T[arraySize];
			for (unsigned int i = 0; i < arraySize; i++)
				arr[i] = other.arr[i];
		}
		return *this;
	}

	T& operator[](unsigned int index) {
		if (index >= arraySize)
			throw std::exception();
		return arr[index];
	}

	unsigned int size() const {
		return arraySize;
	}
};

#endif
