#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie {
public:
	Zombie();
	Zombie(const std::string &name);
	~Zombie();
	void announce();
	void setName(const std::string &name);

	private:
	std::string _name;
};

#endif
