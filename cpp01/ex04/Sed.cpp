#include "Sed.hpp"

Sed::Sed(const std::string &filename, const std::string &str, const std::string &replace) : _filename(filename), _s1(str), _s2(replace) {
	if (_s1.empty()) {
		std::cout << "Error: string1 cannot be empty" << std::endl;
		throw std::exception();
	}
}

Sed::~Sed() {}

void Sed::readAndReplace() {
	std::ifstream inFile = openInFile();
	std::ofstream outFile = openOutFile(inFile);

	std::string line;
	while (std::getline(inFile, line)) {
		replaceString(line, _s1, _s2);
		outFile << line;
		if (!inFile.eof()) {
			outFile << std::endl;
		}
	}

	inFile.close();
	outFile.close();
}

std::ifstream Sed::openInFile() {
	std::ifstream inFile(_filename.c_str());
	if (!inFile.is_open()) {
		std::cout << "Error: Cannot open input file" << std::endl;
		throw std::exception();
	}
	return inFile;
}

std::ofstream Sed::openOutFile(std::ifstream& inFile) {
	std::string outFilename = _filename + ".replace";
	std::ofstream outFile(outFilename.c_str());
	if (!outFile.is_open()) {
		std::cout << "Error: Cannot create output file" << std::endl;
		inFile.close();
		throw std::exception();
	}
	return outFile;
}

void Sed::replaceString(std::string& str, const std::string& from, const std::string& to) {
	std::string result;
	size_t startPos = 0;
	size_t foundPos;
	
	while ((foundPos = str.find(from, startPos)) != std::string::npos) {
		result.append(str, startPos, foundPos - startPos);
		result.append(to);
		startPos = foundPos + from.length();
	}
	result.append(str, startPos, str.length() - startPos);
	str = result;
}
