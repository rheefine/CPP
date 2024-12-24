#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(char *filename) : _filename(filename), _data() {
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	*this = other;
}

BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		_filename = other._filename;
		_data = other._data;
	}
	return *this;
}

void BitcoinExchange::validateDataFile(std::ifstream& file) const {
	std::string line;
	std::getline(file, line);
	if (line != "date,exchange_rate") {
		std::cout << "Error: Invalid data format" << std::endl;
		file.close();
		throw std::exception();
	}
}

void BitcoinExchange::validateInputFile(std::ifstream& file) const {
	std::string line;
	std::getline(file, line);
	if (line != "date | value") {
		std::cout << "Error: invalid header format" << std::endl;
		file.close();
		throw std::exception();
	}
}

bool BitcoinExchange::isValidDate(const std::string& dateStr) {
	if (dateStr.length() != 10) {
		return false;
	}
	if (dateStr[4] != '-' || dateStr[7] != '-') {
		return false;
	}
	for (int i = 0; i < 10; i++) {
		if (i != 4 && i != 7 && !isdigit(dateStr[i])) {
			return false;
		}
	}

	int year = 0, month = 0, day = 0;
	std::istringstream(dateStr.substr(0, 4)) >> year;
	std::istringstream(dateStr.substr(5, 2)) >> month;
	std::istringstream(dateStr.substr(8, 2)) >> day;

	if (year < 1 || month < 1 || month > 12 || day < 1) {
		return false;
	}

	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
		daysInMonth[1] = 29; //윤년
	}

	if (day > daysInMonth[month - 1]) {
		return false;
	}

	return true;
}

void BitcoinExchange::parseData() {
	std::ifstream dataFile("data.csv");
	if (!dataFile.is_open()) {
		std::cout << "Error: could not open file." << std::endl;
		throw std::exception();
	}

	validateDataFile(dataFile);
	std::string line;

	while(getline(dataFile, line)) {
		if (line.empty()) {
			continue;
		}
		size_t commaPos = line.find(',');
		if (commaPos == std::string::npos) {
			std::cout << "Error: invalid data format" << std::endl;
			throw std::exception();
		}
		std::string dateStr = line.substr(0, commaPos);
		if (!isValidDate(dateStr)) {
			std::cout << "Error: invalid data format" << line << std::endl;
			throw std::exception();
		}
		std::string valueStr = line.substr(commaPos + 1);
		std::istringstream iss(valueStr);
		double value;
		iss >> value;
		if (iss.fail() || !iss.eof()) {
			std::cout << "Error: invalid data format" << line << std::endl;
			continue;
		}
		_data[dateStr] = value;
	}
	dataFile.close();
}

void BitcoinExchange::printResult() {
	std::ifstream inputFile(_filename.c_str());
	if (!inputFile.is_open()) {
		std::cout << "Error: could not open file." << std::endl;
		throw std::exception();
	}

	validateInputFile(inputFile);
	std::string line;

	while (std::getline(inputFile, line)) {
		if (line.length() < 13 || line[10] != ' ' || line[11] != '|' || line[12] != ' ') {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string dateStr = line.substr(0, 10);
		std::string valueStr = line.substr(13);

		if (!isValidDate(dateStr)) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		double value;
		std::istringstream iss(valueStr);
		iss >> value;
		if (iss.fail() || !iss.eof()) {
			std::cout << "Error: not a valid number." << std::endl;
			continue;
		}

		if (value < 0) {
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000) {
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}

		std::map<std::string, double>::iterator it = _data.find(dateStr);

		if (it != _data.end()) {
			std::cout << dateStr << " => " << value << " = " << it->second * value << std::endl;
		}
		else {
			if (dateStr < _data.begin()->first) {
				std::cout << "Error: date too early." << std::endl;
			}
			else {
				_data[dateStr] = 0;
				std::map<std::string, double>::iterator it2 = _data.find(dateStr);
				if (it2 != _data.begin()) {
					--it2;
					std::cout << dateStr << " => " << value << " = " << it2->second * value << std::endl;
				}
				_data.erase(dateStr);
			}
		}
	}
	inputFile.close();
}
