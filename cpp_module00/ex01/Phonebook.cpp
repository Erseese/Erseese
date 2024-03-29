/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ersees <ersees@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:22:31 by ytouihar          #+#    #+#             */
/*   Updated: 2024/03/22 21:08:37 by ersees           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"


int	Phonebook::isnum(const std::string &str)
{
	return (std::find_if(str.begin(), str.end(), std::not1(std::ptr_fun(::isdigit))) == str.end());
}

void	Phonebook::fillcontact(int index, int nmbrdeadd)
{
	this->ctontact[index % 7].fill_firstname();
	this->ctontact[index % 7].fill_lastname();
	this->ctontact[index % 7].fill_phonenumber();
	this->ctontact[index % 7].fill_nickname();
	this->ctontact[index % 7].fill_darkest_secret();
	this->ctontact[index % 7].fill_index(index + 1);
	this->nmbrdeadd = nmbrdeadd;
	this->index = index;
}
void	Phonebook::search(void)
{
	int inded = 0;
	std::string input2;
	while (input2 == "")
	{
		std::cout << "Contact index : ";
		std::getline(std::cin, input2);
		if (std::cin.eof())
		{
			std::cin.clear();
			clearerr(stdin);
		}
		std::cout << std::endl;
	}
	if (!isnum(input2))
	{
		std::cout << "Not a number \n";
		return ;
	}
	if ((std::atoi(input2.c_str()) > 8 || std::atoi(input2.c_str()) < 0) || std::atoi(input2.c_str()) > this->nmbrdeadd)
	{
		std::cout << "there is only " << this->nmbrdeadd << " person in the repertory right now sorry..." << std::endl;
		std::cin.clear();
		clearerr(stdin);
		return ;
	}
	std::cout << "Index     " << "|" << "First Name" << "|" << "Last Name " << "|"  << "Nickname " << std::endl;
	while (inded < std::atoi(input2.c_str()))
	{
		this->ctontact[inded].print_lastname(3);
		this->ctontact[inded].print_lastname(0);
		this->ctontact[inded].print_lastname(1);
		this->ctontact[inded].print_lastname(2);
		std::cout << "\n";
		inded++;
	}
}
