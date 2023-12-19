/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:17:14 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/18 12:37:36 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Default constructeur called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Destructeur" << std::endl;
}

FormA*	Intern::Presidential(std::string const target)
{
	return (new PresidentialPardonForm(target));
}
FormA*	Intern::Shrubbery(std::string const target)
{
	return (new ShrubberyCreationForm(target));
}

FormA*	Intern::Robotomy(std::string const target)
{
	return (new RobotomyRequestForm(target));
}

FormA	*Intern::MakeForm(std::string nameform, std::string nametarget)
{
	FormA *(Intern::*tableaudefonction[])(std::string) = {&Intern::Robotomy, &Intern::Presidential, &Intern::Shrubbery};
	std::string allfonc[] = {"Robotomy Request", "Presidential Pardon", "Shrubbery Creation"};
	int y = 0;
	for (int i = 0; i < 3; i++)
	{
		if (nameform.compare(allfonc[i]) == 0)
		{
			return ((this->*tableaudefonction[i])(nametarget));
		}
	}
	if (y != 1)
		throw InternFlopException();
	return (0);
}

Intern::Intern(const Intern &test)
{
	*this = test;
}

Intern &Intern::operator=(Intern const &egal)
{
	(void)egal;
	return (*this);
}

const char *Intern::InternFlopException::what() const throw()
{
	return("noooooooo");
}
