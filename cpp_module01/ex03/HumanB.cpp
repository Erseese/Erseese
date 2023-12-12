/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:45:18 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/11 11:13:27 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _armed(NULL) 
{
	std::cout << "constructeur" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "destructeur" << std::endl;
}

void	HumanB::setWeapon(Weapon &arme)
{
	this->_armed = &arme;
	return ;
}

void	HumanB::attack()
{
	if (this->_armed == NULL)
		std::cout << "pas d arme lol" << std::endl;
	else
		std::cout << this->_name << "> attacks with their " << this->_armed->getType() << std::endl;

	return ;
}