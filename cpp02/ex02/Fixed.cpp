#include "Fixed.hpp"

Fixed::Fixed() : _value(0){
	std::cout << "Default constructor called" << std::endl;
};

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
};

Fixed::Fixed(const Fixed &copy) {
	std::cout << "Copy constructor called" << std::endl;
		_value = copy.getRawBits();
};

Fixed& Fixed::operator=(const Fixed &copy) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy) {
		_value = copy.getRawBits();
	}
	return *this;
};

Fixed::Fixed(int const value) {
	std::cout << "Int constructor called" << std::endl;
	_value = value << _bits;
};

Fixed::Fixed(float const value) {
	std::cout << "Float constructor called" << std::endl;
	_value = static_cast<int>(roundf(value * (1 << _bits)));
};

void Fixed::setRawBits(int const rawBits) {
	_value = rawBits;
};

int Fixed::getRawBits() const {
	return _value;
};

float Fixed::toFloat() const {
	return static_cast<float>(_value) / static_cast<float>(1 << _bits);
};

int Fixed::toInt() const {
	return _value >> _bits;
};

std::ostream &operator<<(std::ostream &out, Fixed const &fixed) {
	out << fixed.toFloat();
	return out;
};
