#ifndef HARL
# define HARL

#include <iostream>

class Harl {
	public:
		Harl();
		~Harl();

		void complain(const std::string &level);

	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);

		int getLevelIndex(const std::string &level);
};

#endif