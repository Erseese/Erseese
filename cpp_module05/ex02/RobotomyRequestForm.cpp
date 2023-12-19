/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:02:24 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/18 10:11:19 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : FormA(72, 45, "RobotomyRequestForm")
{
	std::cout << "constructeur de base !" << std::endl;
	this->_target = "de base";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : FormA(72, 45, "RobotomyRequestForm")
{
	std::cout << "constructeur avec cible !" << std::endl;
	this->_target = target;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "destruction" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &egal)
{	
	if (this != &egal)
	{
		this->_target = egal._target;
	}
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &test)
{
	*this = test;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getbool() == false)
		FormA::NotSigned();
	if (executor.getGrade() > 45)
		FormA::GradeTooLowException();
	
	std::cout << "ici ca drill ca transperse les cieux" << std::endl;
	srand(static_cast<unsigned>(time(0)));
	int randomNumber = rand() % 2;
    if (randomNumber != 0)    
    {
		std::cout << "pti flop" << std::endl;
	}
	else 
		std::cout << "gj" << std::endl;
}