/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:35:23 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/08 14:40:14 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <cctype>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iomanip>

class Weapon{
	private :
	std::string type;

	public : 
	Weapon(const std::string t);
	~Weapon();
	
	void	setType(std::string ttype);
	std::string	getType() const;

};

#endif