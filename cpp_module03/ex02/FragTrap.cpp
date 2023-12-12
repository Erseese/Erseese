/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:06:01 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/12 12:14:51 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "Frag constructor called" << std::endl;
	this->_name = "";
	this->_attack_damages = 30;
	this->_energy = 100;
	this->_hitpoints = 100;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	std::cout << "Frag constructor called" << std::endl;
	this->_name = name;
	this->_attack_damages = 30;
	this->_energy = 100;
	this->_hitpoints = 100;
}
FragTrap::~FragTrap()
{
	std::cout << "Scav destructor called" << std::endl;
}
FragTrap::FragTrap(const FragTrap &copy)
{
	std::cout << "Scav copy constructor called" << std::endl;
	*this = copy;
}
FragTrap &FragTrap::operator=(FragTrap const &egal)
{
	std::cout << "Scav operator = called" << std::endl;
	if (this != &egal)
	{
		this->_name = egal.getName();
		this->_attack_damages = egal.getad();
		this->_energy = egal.getenergy();
		this->_hitpoints = egal.gethp();	
	}
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << " high five request positive j ai rien compris" << std::endl;
}