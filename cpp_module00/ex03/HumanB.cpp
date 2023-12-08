/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:45:18 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/08 14:55:12 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), armed(NULL) 
{
	return ;
}

HumanB::~HumanB()
{
	
}

void	HumanB::setWeapon(Weapon &arme)
{
	this->armed = &arme;
	return ;
}

void	HumanB::attack()
{
	if (this->armed == NULL)
		std::cout << "pas d arme lol" << std::endl;
	else
		std::cout << this->name << "> attacks with their " << this->armed->getType() << std::endl;

	return ;
}