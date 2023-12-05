/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:19:40 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/05 17:11:10 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	#include <iostream>
	#include <string>
	#include <cstdlib>
	#include <cstring>
	#include <iomanip>

class Contact{
	public :
	std::string	phone_number{};
	std::string	first_name{};
	std::string	last_name{};
	std::string	nick_name{};
	std::string	darkest_secret{};
	int	index;
	int nmbretry;
	public :
	void fill_firstname(void)
	{
		std::string test;
		test = "";
		while (this->first_name == test)
		{
			std::cout << "First name : \n";
			std::getline(std::cin, this->first_name);
		}
	}
	void fill_lastname(void)
	{
		std::string test;
		test = "";
		while (this->last_name == test)
		{
			std::cout << "last name : \n";
			std::getline(std::cin, this->last_name);
		}
	}
	void fill_phonenumber(void)
	{
		std::string test;
		test = "";
		while (this->phone_number == test)
		{
			std::cout << "Phone Number : \n";
			std::getline(std::cin, this->phone_number);
		}
	}
	void fill_nickname(void)
	{
		std::string test;
		test = "";
		while (this->nick_name == test)
		{
			std::cout << "Nickname : \n";
			std::getline(std::cin, this->nick_name);
		}
	}
	void fill_darkest_secret(void)
	{
		std::string test;
		test = "";
		while (this->darkest_secret == test)
		{
			std::cout << "Darkest secret : \n";
			std::getline(std::cin, this->darkest_secret);
		}
	}
	void fill_index(int indexs)
	{
		this->index = indexs;
	}
	void print_lastname(int i)
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
	void	print_everythingtest(void)
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
};

class PhoneBook {
	public :
	Contact ctontact[8];
	int	index;
	int	nmbrdeadd;
		
	public :
	void	fillcontact(int index)
	{
		this->ctontact[index % 7].fill_firstname();
		this->ctontact[index % 7].fill_lastname();
		this->ctontact[index % 7].fill_phonenumber();
		this->ctontact[index % 7].fill_nickname();
		this->ctontact[index % 7].fill_darkest_secret();
		this->ctontact[index % 7].fill_index(index + 1);
	}
};



	/*void	fill(std::string y)
	{
		std::string input;
		std::cout << "First name : \n";
		std::getline(std::cin, test.first_name);
	}*/

void	testprint(Contact test)
{
	
	std::cout << test.phone_number;
	std::cout << "\n";
	std::cout << test.first_name;
	std::cout << "\n";
	std::cout << test.last_name;
	std::cout << "\n";
	std::cout << test.nick_name;
	std::cout << "\n";
	std::cout << test.darkest_secret;
	std::cout << "\n";
}

int main(void) 
{
	int		index = 0;
	Contact test;
	PhoneBook tfullest;
	tfullest.index = 0;
	tfullest.nmbrdeadd = 0;
	while (1)
	{	
		std::string input;
		std::cout << "Print a command\n";
		std::getline(std::cin, input);
		if (input.compare("ADD") == 0)
		{
			tfullest.fillcontact(tfullest.index);
			tfullest.nmbrdeadd++;
			tfullest.index++;
		}
		else if (input.compare("EXIT") == 0)
			return (0);
		else if (input.compare("SEARCH") == 0)
		{
			int inded = 0;
			std::cout << "contact index : ";
       		std::cin >> input;
			if ((std::atoi(input.c_str()) > 8 || std::atoi(input.c_str()) < 0) || std::atoi(input.c_str()) < tfullest.nmbrdeadd)
				return (0);
			std::cout << "Index     " << "|" << "First Name" << "|" << "Last Name " << "|"  << "Nickname  " << std::endl;
			while (inded < std::atoi(input.c_str()))
			{
				tfullest.ctontact[inded].print_lastname(3);
				tfullest.ctontact[inded].print_lastname(0);
				tfullest.ctontact[inded].print_lastname(1);
				tfullest.ctontact[inded].print_lastname(2);
				std::cout << "\n";
				inded++;
			}
			return (0);
		}
	}
	//tfullest.ctontact[0].print_everythingtest();
	return 0;
}
