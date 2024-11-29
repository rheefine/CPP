#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {
	*this = src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src) {
	(void)src;
	return *this;
}

void ScalarConverter::convert(char *input) {
	char *endptr;
	double d;

    if (strlen(input) == 1) {
        d = static_cast<double>(input[0]);
	} else {
        d = strtod(input, &endptr);
        if (input == endptr && strlen(input) != 1)
            throw ScalarConverter::InvalidInputException();
        if (*endptr != '\0' && *endptr != 'f')
            throw ScalarConverter::InvalidInputException();
    }

	try {
		std::cout << "char: ";
		std::cout << ScalarConverter::convertChar(d) << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "int: ";
		std::cout << ScalarConverter::convertInt(d) << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::fixed;
    std::cout.precision(1);

	std::cout << "float: ";
	std::cout << ScalarConverter::convertFloat(d) << "f" << std::endl;

	std::cout << "double: ";
	std::cout << ScalarConverter::convertDouble(d) << std::endl;
}

char ScalarConverter::convertChar(double d) {
	if (isnan(d) || isinf(d) || d < CHAR_MIN || d > CHAR_MAX)
		throw ScalarConverter::ImpossibleException();
	char c = static_cast<char>(d);
	if (c < 32 || c > 126)
		throw ScalarConverter::NonDisplayableException();
	return c;
}

int ScalarConverter::convertInt(double d) {
	if (isnan(d) || isinf(d) || d < INT_MIN || d > INT_MAX)
		throw ScalarConverter::ImpossibleException();
	int i = static_cast<int>(d);
	return i;
}

float ScalarConverter::convertFloat(double d) {
	float f = static_cast<float>(d);
	return f;
}

double ScalarConverter::convertDouble(double d) {
	return d;
}

const char *ScalarConverter::ImpossibleException::what() const throw() {
	return "impossible";
}

const char *ScalarConverter::NonDisplayableException::what() const throw() {
	return "Non displayable";
}

const char *ScalarConverter::InvalidInputException::what() const throw() {
	return "Invalid Input";
}