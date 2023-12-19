/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:49:15 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/12 15:35:25 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << " constructeur WrongCat cree" << std::endl;
	this->_type = "cat";
}

WrongCat::WrongCat(std::string type)
{
	std::cout << " constructeur WrongCat type cree" << std::endl;
	this->_type = type;
}

WrongCat::~WrongCat()
{
	std::cout << " WrongCat destructiSDIOFSAFHOSIAD" << std::endl;
}

WrongCat::WrongCat(WrongCat const &copy)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = copy;
}

WrongCat &WrongCat::operator=(WrongCat const &egal)
{
	std::cout << "operator = WrongCat called yippie" << std::endl;
	if (this != &egal)
		this->_type = egal.gettype();
	return *this;
}

void	WrongCat::makeSound() const
{
	std::cout << "maou" << std::endl;
}