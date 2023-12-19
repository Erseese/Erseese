/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:23:17 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/12 15:36:13 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << " constructeur Cat cree" << std::endl;
	this->_type = "Cat";
}

Cat::Cat(std::string type)
{
	std::cout << " constructeur Cat type cree" << std::endl;
	this->_type = type;
}

Cat::~Cat()
{
	std::cout << " Cat destructiSDIOFSAFHOSIAD" << std::endl;
}

Cat::Cat(Cat const &copy)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = copy;
}

Cat &Cat::operator=(Cat const &egal)
{
	std::cout << "operator = Cat called yippie" << std::endl;
	if (this != &egal)
		this->_type = egal.gettype();
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "maou" << std::endl;
}