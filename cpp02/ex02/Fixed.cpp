#include "Fixed.hpp"

Fixed::Fixed() : _value(0){
	// std::cout << "Default constructor called" << std::endl;
};

Fixed::~Fixed() {
	// std::cout << "Destructor called" << std::endl;
};

Fixed::Fixed(const Fixed &copy) {
	// std::cout << "Copy constructor called" << std::endl;
		_value = copy.getRawBits();
};

Fixed& Fixed::operator=(const Fixed &copy) {
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy) {
		_value = copy.getRawBits();
	}
	return *this;
};

Fixed::Fixed(int const value) {
	// std::cout << "Int constructor called" << std::endl;
	_value = value << _bits;
};

Fixed::Fixed(float const value) {
	// std::cout << "Float constructor called" << std::endl;
	_value = static_cast<int>(roundf(value * (1 << _bits)));
};

void Fixed::setRawBits(int const raw) {
	// std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
};

int Fixed::getRawBits() const {
	// std::cout << "getRawBits member function called" << std::endl;
	return _value;
};

float Fixed::toFloat() const {
	return static_cast<float>(_value) / static_cast<float>(1 << _bits);
};

int Fixed::toInt() const {
	return _value >> _bits;
};

// 비교 연산자
bool Fixed::operator>(const Fixed &other) const {
	return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator<(const Fixed &other) const {
	return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other) const {
	return this->getRawBits() >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other) const {
	return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator==(const Fixed &other) const {
	return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const {
	return this->getRawBits() != other.getRawBits();
}

// 산술 연산자
Fixed Fixed::operator+(const Fixed &other) const {
	Fixed result;
	result.setRawBits(this->getRawBits() + other.getRawBits());
	return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
	Fixed result;
	result.setRawBits(this->getRawBits() - other.getRawBits());
	return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
	Fixed result;
	long long temp = static_cast<long long>(this->getRawBits()) * static_cast<long long>(other.getRawBits());
	result.setRawBits(temp >> _bits);
	return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
	Fixed result;
	long long temp = static_cast<long long>(this->getRawBits()) << _bits;
	result.setRawBits(temp / other.getRawBits());
	return result;
}

// 증감 연산자
Fixed& Fixed::operator++() {
	this->_value++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	++(*this);
	return temp;
}

Fixed& Fixed::operator--() {
	this->_value--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	--(*this);
	return temp;
}

// min, max 함수
Fixed& Fixed::min(Fixed &a, Fixed &b) {
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
	return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &out, Fixed const &fixed) {
	out << fixed.toFloat();
	return out;
};
