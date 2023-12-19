/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:21:38 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/12 16:59:04 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() 
{
	std::cout << "brain const." << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "yey";
}

Brain::~Brain()
{
	std::cout << "brain destr." << std::endl;
}

Brain::Brain(const Brain &test)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = test._ideas[i];
}

Brain &Brain::operator=(Brain const &egal)
{
	if (this != &egal)
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = egal._ideas[i];

	return *this;
}

void	Brain::printFirstIdeas(void) const
{
	std::cout << "Ideas : " << _ideas[0] << "," << _ideas[1] << "," << _ideas[2] << "," << _ideas[3] << "," << _ideas[4] << ",... ";
}