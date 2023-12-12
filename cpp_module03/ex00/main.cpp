/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:11:53 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/12 11:00:54 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	std::string pseudo = "Ersees";
	ClapTrap Ersito(pseudo);
	for (int i = 0; i < 9; i++)
		Ersito.attack("test");
	Ersito.beRepaired(70);
	Ersito.gethp();
	Ersito.getenergy();
	Ersito.takeDamage(30);
	Ersito.gethp();
	Ersito.beRepaired(5);
}