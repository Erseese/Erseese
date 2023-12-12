/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:05:54 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/12 12:14:20 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public :
	FragTrap();
	FragTrap(const std::string name);
	~FragTrap();
	FragTrap(const FragTrap &copy);
	FragTrap &operator=(FragTrap const &egal);
	
	void	highFivesGuys(void);
};

#endif