/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:11:53 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/12 12:14:29 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	std::string pseudo = "Ersees";
	ClapTrap Errsito(pseudo);
	for (int i = 0; i < 9; i++)
		Errsito.attack("test");
	Errsito.beRepaired(70);
	Errsito.gethp();
	Errsito.getenergy();
	Errsito.takeDamage(30);
	//Errsito.guardGate();
	Errsito.gethp();
	Errsito.beRepaired(5);
	
	ScavTrap Ersito(pseudo);
	for (int i = 0; i < 9; i++)
		Ersito.attack("test");
	Ersito.beRepaired(70);
	Ersito.gethp();
	Ersito.getenergy();
	Ersito.takeDamage(30);
	Ersito.guardGate();
	Ersito.gethp();
	Ersito.beRepaired(5);
	
	FragTrap Eersito(pseudo);
	for (int i = 0; i < 9; i++)
		Eersito.attack("test");
	Eersito.beRepaired(70);
	Eersito.gethp();
	Eersito.getenergy();
	Eersito.takeDamage(30);
	Eersito.highFivesGuys();
	Eersito.gethp();
	Eersito.beRepaired(5);
	
}