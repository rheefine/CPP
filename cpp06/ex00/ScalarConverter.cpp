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
	double d = strtod(input, &endptr);

	std::cout << "char: ";
	std::cout << ScalarConverter::convertChar(d) << std::endl;
	std::cout << "int: ";
	std::cout << ScalarConverter::convertInt(d) << std::endl;
	std::cout << "float: ";
	std::cout << ScalarConverter::convertFloat(d) << std::endl;
	std::cout << "double: ";
	std::cout << ScalarConverter::convertDouble(d) << std::endl;
}

char ScalarConverter::convertChar(double d) {
	char c = static_cast<char>(d);
	if (c < 32 || c > 126)
		throw ScalarConverter::ImpossibleException();
	return c;
}

int ScalarConverter::convertInt(double d) {
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

