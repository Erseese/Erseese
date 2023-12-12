/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:59:17 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/11 11:12:58 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string n, const Weapon &w) : _armed(w), _name(n)
{
	return ;
}

HumanA::~HumanA()
{
	return;
}

void	HumanA::attack()
{
	std::cout << this->_name << "> attacks with their " << this->_armed.getType() << std::endl;
}