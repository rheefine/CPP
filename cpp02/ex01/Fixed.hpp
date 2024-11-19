#ifndef FIXED_HPP
 #define FIXED_HPP

#include <iostream>

class Fixed {
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &fixed);
		Fixed &operator= (const Fixed &copy);

		Fixed(int const value);
		Fixed(float const value);

		int getRawBits() const;
		void setRawBits(int const raw);

		float toFloat() const;
		int toInt() const;

	private:
		int _value;
		static const int _bits = 8;
};

std::ostream &operator<<(std::ostream &out, Fixed const &fixed);

#endif
