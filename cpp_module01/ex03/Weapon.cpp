/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:35:14 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/08 14:42:11 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string t) : type(t)
{
	return; 
}

Weapon::~Weapon()
{
	return;
}

void	Weapon::setType(std::string ttype)
{
	this->type = ttype;
}
std::string	Weapon::getType() const
{
	return (this->type);
}