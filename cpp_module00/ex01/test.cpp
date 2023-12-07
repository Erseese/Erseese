/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:19:40 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/07 16:33:58 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int main(void) 
{
	Phonebook tfullest;
	int index = 0;
	int nmbrdeadd = 0;
	std::string input;
	while (1)
	{
		if (std::cin.eof())
			std::cin.clear(std::cin.goodbit);
		std::cout << "Print a command" << std::endl;
		std::cin >> std::ws;
		std::getline(std::cin, input);
		if (input.compare("ADD") == 0)
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
		std::cin.clear(std::cin.goodbit);
		clearerr(stdin);
	}
	return 0;
}
