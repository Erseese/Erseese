/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:42:44 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/08 14:55:32 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB{
	private :
	std::string name;
	Weapon *armed;

	public :
	HumanB(std::string name);
	~HumanB();

	void	setWeapon(Weapon &arme);
	void	attack();
};

#endif