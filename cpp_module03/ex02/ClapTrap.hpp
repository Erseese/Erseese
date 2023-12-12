/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:11:51 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/12 11:48:08 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	protected :
	std::string _name;
	int			_hitpoints;
	int			_energy;
	int			_attack_damages;

	public :
	ClapTrap();
	ClapTrap(const std::string name);
	~ClapTrap();
	ClapTrap(const ClapTrap &copy);
	ClapTrap &operator=(ClapTrap const &egal);

	std::string	getName(void) const;
	int			gethp(void) const;
	int			getenergy(void) const;
	int			getad(void) const;
	

	void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

//std::ostream	&operator<<(std::ostream &out, const ClapTrap &yipie);

#endif