
#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	protected :
	std::string _type;

	public :
	WrongAnimal();
	WrongAnimal(std::string type);
	~WrongAnimal();
	WrongAnimal(WrongAnimal const &copy);
	std::string gettype() const;
	WrongAnimal &operator=(WrongAnimal const &egal);

	void makeSound() const;
};

#endif