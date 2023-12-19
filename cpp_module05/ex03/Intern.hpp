/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:19:05 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/18 12:22:37 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>

class Intern{

public :
	Intern();
	~Intern();
	FormA	*Robotomy(std::string const target);
	FormA	*Shrubbery(std::string const target);
	FormA	*Presidential(std::string const target);
	FormA *MakeForm(std::string nameform, std::string nametarget);
	Intern(const Intern &test);
	Intern &operator=(Intern const &egal);
	class InternFlopException : public std::exception
	{
		public :
			virtual const char* what() const throw();
	};

};
#endif