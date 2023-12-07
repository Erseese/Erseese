/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:22:31 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/07 16:41:30 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook()
{
}

int	Phonebook::isnum(const std::string &str)
{
	return (std::all_of(str.begin(), str.end(), ::isdigit));
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
	std::cout << "contact index : ";
	std::cin >> input2;
	if (!isnum(input2))
		return ;
	if ((std::atoi(input2.c_str()) > 8 || std::atoi(input2.c_str()) < 0) || std::atoi(input2.c_str()) > this->nmbrdeadd)
	{
		std::cout << this->nmbrdeadd;
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