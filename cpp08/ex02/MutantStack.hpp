#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack() : std::stack<T>() {}
	MutantStack(const MutantStack& other) : std::stack<T>(other) {}
	virtual ~MutantStack() {}
	MutantStack& operator=(const MutantStack& other) {
		if (this != &other)
			std::stack<T>::operator=(other);
		return *this;
	}

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
	reverse_iterator rbegin() { return this->c.rbegin(); }
	reverse_iterator rend() { return this->c.rend(); }
};

#endif
