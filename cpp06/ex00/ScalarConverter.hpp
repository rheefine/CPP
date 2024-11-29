#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

class ScalarConverter {
	public:
		static void convert(char *input);

	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter &operator=(const ScalarConverter &src);

		static char convertChar(double d);
		static int convertInt(double d);
		static float convertFloat(double d);
		static double convertDouble(double d);

		class ImpossibleException : public std::exception {
			public:
				const char *what() const throw();
		};
		class NonDisplayableException : public std::exception {
			public:
				const char *what() const throw();
		};
		class InvalidInputException : public std::exception {
			public:
				const char *what() const throw();
		};

};

#endif
