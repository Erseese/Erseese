/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:03:38 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/08 12:03:47 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*test;
	Zombie	*yes;
	int		n = 7;

	std::string input;
	std::cout<< "Ecrivez un zomblard:";
	std::cin >> std::ws;
	std::getline(std::cin, input);
	test = newZombie(input);
	test->announce();
	std::cin.clear(std::cin.goodbit);
	std::cout<< "Ecrivez un zomblard:";
	std::cin >> std::ws;
	std::getline(std::cin, input);
	yes = zombieHorde(n ,input);
	
	for (int i = 0; i < n; i++)
		yes[i].announce();
	delete[] yes;
	delete test;
	return (0);
}