/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:14:14 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/11 11:14:29 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <cctype>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iomanip>

class Zombie{
	private : 
	std::string _name;

	public :
	Zombie() : _name("") {}

	Zombie(std::string name);
	~Zombie();

	void	announce(void);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif