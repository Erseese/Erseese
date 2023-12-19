/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:10:27 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/12 16:47:39 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << " constructeur Animal cree" << std::endl;
	this->_type = "idk";
}

Animal::~Animal()
{
	std::cout << " Animal desstructiSDIOHSAFHOSIAD" << std::endl;
}

Animal::Animal(Animal const &copy)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = copy;
}


std::string Animal::gettype() const
{
	//std::cout << "his type is " << this->_type << std::endl;
	return (this->_type);
}


Animal &Animal::operator=(Animal const &egal)
{
	std::cout << "operator = Animal called yippie" << std::endl;
	if (this != &egal)
		this->_type = egal._type;
	return *this;
}

void	Animal::makeSound() const
{
	std::cout << "animal sound boom" << std::endl;
}