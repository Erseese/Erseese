/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:50:50 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/07 17:09:20 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::fill_firstname(void)
{
	std::string test;
	test = "";
	while (this->first_name == test)
	{
		std::cout << "First name : \n";
		std::getline(std::cin, this->first_name);
	}
}
void Contact::fill_lastname(void)
{
	std::string test;
	test = "";
	while (this->last_name == test)
	{
		std::cout << "last name : \n";
		std::getline(std::cin, this->last_name);
	}
}
void Contact::fill_phonenumber(void)
{
	std::string test;
	test = "";
	while (this->phone_number == test)
	{
		std::cout << "Phone Number : \n";
		std::getline(std::cin, this->phone_number);
	}
}
void Contact::fill_nickname(void)
{
	std::string test;
	test = "";
	while (this->nick_name == test)
	{
		std::cout << "Nickname : \n";
		std::getline(std::cin, this->nick_name);
	}
}
void Contact::fill_darkest_secret(void)
{
	std::string test;
	test = "";
	while (this->darkest_secret == test)
	{
		std::cout << "Darkest secret : \n";
		std::getline(std::cin, this->darkest_secret);
	}
}
void Contact::fill_index(int indexs)
{
	this->index = indexs;
}
void Contact::print_lastname(int i)
{
	if (i == 0)
	{
		if (this->first_name.length() < 10)
			std::cout << std::setw(10) << this->first_name << '|';
		else
			std::cout<< this->first_name.substr(0, 9) << '.' << '|';
	}
	if (i == 1)
	{
		if (this->last_name.length() < 10)
			std::cout << std::setw(10) << this->last_name << '|';
		else
			std::cout<< this->last_name.substr(0, 9) << '.' << '|';
	}
	if (i == 2)
	{
		if (this->nick_name.length() < 10)
			std::cout << std::setw(10) << this->nick_name;
		else
			std::cout<< this->nick_name.substr(0, 9) << '.';
	}
	if (i == 3)
		std::cout << std::setw(10) << this->index << '|';
}
void	Contact::print_everythingtest(void)
{
	std::cout << this->phone_number;
	std::cout << "\n";
	std::cout << this->first_name;
	std::cout << "\n";
	std::cout << this->last_name;
	std::cout << "\n";
	std::cout << this->nick_name;
	std::cout << "\n";
	//std::cout << this->index;	
	//std::cout << "\n";
	std::cout << this->darkest_secret;
	std::cout << "\n";
}