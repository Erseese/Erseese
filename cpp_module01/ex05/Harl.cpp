/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 16:27:45 by ersees            #+#    #+#             */
/*   Updated: 2023/12/11 11:16:25 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "constructeur" << std::endl;
}

Harl::~Harl()
{
	std::cout << "destructeur" << std::endl;
}

void	Harl::_debug(void)
{
	std::cout << "idk debug" << std::endl;
}
void	Harl::_error(void)
{
	std::cout << "idk error" << std::endl;
}
void	Harl::_info(void)
{
	std::cout << "idk info" << std::endl;
}
void	Harl::_warning(void)
{
	std::cout << "idk warning" << std::endl;
}

void	Harl::complain(std::string level)
{
	int i = 0;
	void (Harl::*tableaudefonction[])(void) = {&Harl::_debug, &Harl::_error, &Harl::_info, &Harl::_warning};

	std::string test[] = {"debug", "error", "info", "warning"};
	while (i < 4)
	{
		if (level.compare(test[i]) == 0)
		{
			(this->*tableaudefonction[i])();
			break;
		}
		i++;
	}
}