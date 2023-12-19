/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:10:27 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/12 17:08:42 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << " constructeur Animal cree" << std::endl;
	this->_type = "idk";
	this->_brain = new Brain();
}

Animal::~Animal()
{
	std::cout << " Animal destru" << std::endl;
	delete this->_brain;
}

Animal::Animal(Animal const &copy)
{
	std::cout << "Animal copy constructor called" << std::endl;
	this->_brain = copy._brain;
	this->_type = copy._type;
}


std::string Animal::gettype() const
{
	//std::cout << "his type is " << this->type << std::endl;
	return (this->_type);
}


Animal &Animal::operator=(Animal const &egal)
{
	std::cout << "operator = Animal called yippie" << std::endl;
	if (this != &egal)
	{
		this->_type = egal._type;
		this->_brain = egal._brain;
	}
	return *this;
}

void	Animal::makeSound() const
{
	std::cout << "animal sound boom" << std::endl;
}

void	Animal::printIdeas(void) const
{
	this->_brain->printFirstIdeas();
	std::cout << " at " << &this->_brain << std::endl;
}