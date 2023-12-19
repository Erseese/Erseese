/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:48:07 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/12 16:50:41 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << " constructeur WrongAnimal cree" << std::endl;
	this->_type = "idk";
}

WrongAnimal::WrongAnimal(std::string type)
{
	std::cout << " constructeur WrongAnimal type cree" << std::endl;
	this->_type = type;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << " WrongAnimal desstructiSDIOHSAFHOSIAD" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &copy)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = copy;
}


std::string WrongAnimal::gettype() const
{
	//std::cout << "his type is " << this->type << std::endl;
	return (this->_type);
}


WrongAnimal &WrongAnimal::operator=(WrongAnimal const &egal)
{
	std::cout << "operator = WrongAnimal called yippie" << std::endl;
	if (this != &egal)
		this->_type = egal.gettype();
	return *this;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "Wronganimal sound boom" << std::endl;
}