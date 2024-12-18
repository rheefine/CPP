#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template<typename T>
void iter(T* array, size_t length, void (*f)(T const &)) {
	if (!array || !f)
		return;
	for (size_t i = 0; i < length; i++) {
		f(array[i]);
	}
}

#endif
