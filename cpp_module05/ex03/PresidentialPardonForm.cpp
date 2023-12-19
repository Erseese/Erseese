/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 18:28:18 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/18 12:47:36 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : FormA(25, 5, "PresidentialPardonForm")
{
	std::cout << "constructeur de base !" << std::endl;
	this->_target = "de base";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : FormA(25, 5, "PresidentialPardonForm")
{
	std::cout << "constructeur avec cible !" << std::endl;
	this->_target = target;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "destruction" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &egal)
{	
	if (this != &egal)
	{
		this->_target = egal._target;
	}
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &test)
{
	*this = test;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getbool() == false)
		throw (FormA::NotSigned());
	if (executor.getGrade() > 5)
		throw (FormA::GradeTooLowException());
	std::cout << this->_target <<" has been pardoned by Zaphod Beeblebrox." << std::endl;
}