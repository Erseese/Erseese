/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:29:06 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/15 16:17:39 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << " constructeur Dog cree" << std::endl;
	this->_type = "Chien";
	brain = new Brain();
}

Dog::Dog(std::string type)
{
	std::cout << " constructeur Dog type cree" << std::endl;
	this->_type = type;
	brain = new Brain();
}

Dog::~Dog()
{
	std::cout << " Dog destruct" << std::endl;
	delete brain;
}

Dog::Dog(Dog const &copy)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = copy;
}

Dog &Dog::operator=(Dog const &egal)
{
	std::cout << "operator = Dog called yippie" << std::endl;
	this->_type = egal._type;
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "ouf" << std::endl;
}