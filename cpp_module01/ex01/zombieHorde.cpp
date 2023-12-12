/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:33:25 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/08 14:01:47 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name )
{
	Zombie *horde = new Zombie[N];
	for(int i = 0; i < N; i++)
		horde[i] = Zombie(name);
	return (horde);
}