/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:14:50 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/12 12:10:45 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "Scav constructor called" << std::endl;
	this->_name = "";
	this->_attack_damages = 20;
	this->_energy = 50;
	this->_hitpoints = 100;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
	std::cout << "Scav constructor called" << std::endl;
	this->_name = name;
	this->_attack_damages = 20;
	this->_energy = 50;
	this->_hitpoints = 100;
}
ScavTrap::~ScavTrap()
{
	std::cout << "Scav destructor called" << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap &copy)
{
	std::cout << "Scav copy constructor called" << std::endl;
	*this = copy;
}
ScavTrap &ScavTrap::operator=(ScavTrap const &egal)
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

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " is in guard gate mode" << std::endl;
}