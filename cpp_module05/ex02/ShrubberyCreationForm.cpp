/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:02:28 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/18 10:06:21 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : FormA(145, 137, "ShrubberyCreationForm")
{
	std::cout << "constructeur de base !" << std::endl;
	this->_target = "de base";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : FormA(145, 137, "ShrubberyCreationForm")
{
	std::cout << "constructeur avec cible !" << std::endl;
	this->_target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "destruction" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &egal)
{	
	if (this != &egal)
	{
		this->_target = egal._target;
	}
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &test)
{
	*this = test;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getbool() == false)
		FormA::NotSigned();
	if (executor.getGrade() > 137)
		FormA::GradeTooLowException();
	
	std::string const arbre(this->_target + "_shrubbery");
    std::ofstream arbre_file(arbre.c_str());
    if (arbre_file != 0)    
    {
		arbre_file << "arbre binaire" << std::endl;
	}
	else 
	std::cout << "error file opening" << std::endl;
}