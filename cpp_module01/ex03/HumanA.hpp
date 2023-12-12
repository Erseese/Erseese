/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:51:20 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/11 11:12:13 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA{
	private : 
	const Weapon		&_armed;
	std::string	_name;

	public :
	HumanA(const std::string n, const Weapon &w);
	~HumanA();
	
	void	attack();
};

#endif