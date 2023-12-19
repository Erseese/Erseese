/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:49:27 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/17 16:22:03 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():_name("Default"), _grade(150)
{
    std::cout << "Default constructeur called" << std::endl;
}

Bureaucrat::Bureaucrat(int grade, std::string name) 
{
	std::cout << "constructeur" << std::endl;
	if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
	else if (grade < 0)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
	this->_name = name;
}
Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructeur" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &test)
{
	*this = test;
}

std::string	Bureaucrat::getName(void) const
{
	std::cout << "Name : " << _name << std::endl;
	return (_name);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("ptit flop de ta part tu feras mieux la prochaien fois trop haut\n");
}
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("ptit flop de ta part tu feras mieux la prochaien fois trop bas\n");
}

int		Bureaucrat::getGrade(void) const
{
	std::cout << "Grade : " << _grade << std::endl;
	return (_grade);
}

void	Bureaucrat::upgrade(int unsigned const grade)
{
	if (this->_grade + grade > 150)
		throw Bureaucrat::GradeTooHighException();
	std::cout << "Grade upgrade from : " << _grade << std::endl;
	this->_grade += grade;
	std::cout << " to : " << _grade << std::endl;
}

void	Bureaucrat::downgrade(int unsigned const grade)
{
	if (this->_grade - grade < 0)
	{
		std::cout << "Grade too low to diminuer mdr" << std::endl;
		throw Bureaucrat::GradeTooLowException();
		return ;
	}
	std::cout << "Grade downgrade from : " << _grade << std::endl;
	this->_grade -= grade;
	std::cout << " to : " << _grade << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &egal)
{	
	if (this != &egal)
	{
		this->_name = egal._name;
		this->_grade = egal._grade;
	}
	return (*this);
}

std::ostream    &operator<<(std::ostream &out, const Bureaucrat &Bureaucrat)
{
    out << Bureaucrat.getName()	<< "bureaucrat grade" << Bureaucrat.getGrade() << std::endl;
    return (out);
}
