#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
	public :
		Brain();
		Brain(const Brain& other);
		~Brain();
		Brain& operator=(const Brain& other);

		void setIdea(int i, std::string idea);
		std::string getIdea(int i) const;

	private :
		std::string _ideas[100];

};

#endif
