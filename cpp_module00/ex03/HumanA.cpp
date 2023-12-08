/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:59:17 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/08 14:32:41 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string n, const Weapon &w) : armed(w), name(n)
{
	return ;
}

HumanA::~HumanA()
{
	return;
}

void	HumanA::attack()
{
	std::cout << this->name << "> attacks with their " << this->armed.getType() << std::endl;
}