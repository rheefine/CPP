#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>


class Span {
	public:
		Span();
		Span(unsigned int n);
		Span(const Span &other);
		~Span();
		Span &operator=(const Span &other);

		void addNumber(int n);
		int shortestSpan();
		int longestSpan();

		template <typename T>
		void addNumbers(T begin, T end) {
			while (begin != end) {
				addNumber(*begin);
				begin++;
			}
		}

	private:
		unsigned int _n;
		std::vector<int> _numbers;

};

#endif
