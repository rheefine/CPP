#ifndef SED
# define SED

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

class Sed {
	public:
		Sed(const std::string &filename, const std::string &str, const std::string &replace);
		~Sed();
		void readAndReplace();

	private:
	std::string _filename;
	std::string _s1;
	std::string _s2;

	void replaceString(std::string& str, const std::string& from, const std::string& to);

};

#endif
