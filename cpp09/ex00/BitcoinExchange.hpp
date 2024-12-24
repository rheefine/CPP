#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>

class BitcoinExchange {
	public:
		BitcoinExchange(char *filename);
		BitcoinExchange(const BitcoinExchange &other);
		~BitcoinExchange();
		BitcoinExchange &operator=(const BitcoinExchange &other);
		void parseData();
		void printResult();

	private:
		std::string _filename;
		std::map<std::string, double> _data;
		bool isValidDate(const std::string& dateStr);
		void validateDataFile(std::ifstream& file) const;
		void validateInputFile(std::ifstream& file) const;
};

#endif
