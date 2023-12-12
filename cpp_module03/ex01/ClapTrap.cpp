/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:11:47 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/12 11:48:31 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "constructor called" << std::endl;
	this->_name = "";
	this->_attack_damages = 0;
	this->_energy = 10;
	this->_hitpoints = 10;
}

ClapTrap::ClapTrap(const std::string name)
{
	std::cout << "Clap constructor called" << std::endl;
	this->_name = name;
	this->_attack_damages = 0;
	this->_energy = 10;
	this->_hitpoints = 10;
}
ClapTrap::~ClapTrap()
{
	std::cout << "Clap destructor called" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "Clap copy constructor called" << std::endl;
	*this = copy;
}
ClapTrap &ClapTrap::operator=(ClapTrap const &egal)
{
	std::cout << "Clap operator = called" << std::endl;
	if (this != &egal)
	{
		this->_name = egal.getName();
		this->_attack_damages = egal.getad();
		this->_energy = egal.getenergy();
		this->_hitpoints = egal.gethp();	
	}
	return (*this);
}

std::string	ClapTrap::getName(void) const
{
	std::cout << "his name is " << this->_name << std::endl;
	return (this->_name);
}
int			ClapTrap::gethp(void) const
{
	std::cout << "he has " << this->_hitpoints << " hp" << std::endl;
	return (this->_hitpoints);
}
int			ClapTrap::getad(void) const
{
	std::cout << "he has " << this->_attack_damages << " ad" << std::endl;
	return (this->_attack_damages);
}
int			ClapTrap::getenergy(void) const
{
	std::cout << "he has " << this->_energy << " energy" << std::endl;
	return (this->_energy);
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_hitpoints > 0)
	{
		if ( this->_energy > 0)
		{
			std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damages << " points of damage!" << std::endl;
			this->_energy--;
		}
		else
			std::cout << "cant attack no energy flop" << std::endl;
	}
	else 
		std::cout << "cant attack no hp left sadge" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitpoints > 0)
	{
		this->_hitpoints -= amount;
		if (this->_hitpoints > 0)
			std::cout << "ClapTrap " << this->_name << " took" << amount << " points of damage! He only have "<< this->_hitpoints << " left" << std::endl;
		else
		{
			this->_hitpoints = 0;
			std::cout << "ClapTrap " << this->_name << " died" << std::endl;
		}
	}
	else
		std::cout << "he is already dead..." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitpoints > 0)
	{
		if ( this->_energy > 0)
		{
			std::cout << "ClapTrap " << this->_name << " heals himself for "  << amount << " HP !" << std::endl;
			this->_hitpoints += amount;
			this->_energy--;
		}
		else
			std::cout << "cant heal himself... no energy flop" << std::endl;
	}
	else 
		std::cout << "cant heal himself because he is already dead... sadge" << std::endl;
}

/*std::ostream	&operator<<(std::ostream &out, const ClapTrap &yipie)
{
	std::cout "operator << called" << std::endl;
	out << 
}*/