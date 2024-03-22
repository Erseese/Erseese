/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ersees <ersees@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:19:40 by ytouihar          #+#    #+#             */
/*   Updated: 2024/03/22 21:06:08 by ersees           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <cstdio>

int main(void) 
{
	Phonebook tfullest;
	int index = 0;
	int nmbrdeadd = 0;
	std::string input;
	while (1)
	{
		std::cout << "Print a command" << std::endl;
		std::cin >> std::ws;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cin.clear();
			clearerr(stdin);
		}
		else if (input.compare("ADD") == 0)
		{
			nmbrdeadd++;
			tfullest.fillcontact(index, nmbrdeadd);
			index++;
		}
		else if (input.compare("EXIT") == 0)
			return (0);
		else if (input.compare("SEARCH") == 0)
		{
			tfullest.search();
		}
		std::cin.clear();
		clearerr(stdin);
	}
	return 0;
}

