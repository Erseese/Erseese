/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FormA.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:40:51 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/18 09:31:29 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FormA.hpp"

FormA::FormA():_name("Default"), _signed(false), _grade_sign(50), _grade_exec(75)
{
    std::cout << "Default constructeur called" << std::endl;
}

FormA::FormA(int grade_sign, int grade_exec, std::string name) 
{
	std::cout << "constructeur" << std::endl;
	if (grade_sign > 150 || grade_exec > 150)
		throw FormA::GradeTooHighException();
	else if (grade_exec < 0 || grade_sign < 0)
		throw FormA::GradeTooLowException();
	this->_grade_sign = grade_sign;
	this->_grade_exec = grade_exec;
	this->_signed = false;
	this->_name = name;
}
FormA::~FormA()
{
	std::cout << "Destructeur" << std::endl;
}

FormA::FormA(const FormA &test)
{
	*this = test;
}

std::string	FormA::getName(void) const
{
	std::cout << "Name : " << _name << std::endl;
	return (_name);
}

const char *FormA::GradeTooHighException::what() const throw()
{
	return ("ptit flop de ta part tu feras mieux la prochaien fois trop haut\n");
}
const char *FormA::GradeTooLowException::what() const throw()
{
	return ("ptit flop de ta part tu feras mieux la prochaien fois trop bas\n");
}

const char *FormA::NotSigned::what() const throw()
{
	return ("ptit flop de ta part tu feras mieux la prochaien fois pas signed\n");
}

int		FormA::getExecGrade(void) const
{
	std::cout << "Grade exec : " << _grade_exec << std::endl;
	return (_grade_exec);
}
int		FormA::getSignGrade(void) const
{
	std::cout << "Grade sign : " << _grade_sign << std::endl;
	return (_grade_sign);
}

bool		FormA::getbool(void) const
{
	std::cout << "bool : " << _signed << std::endl;
	return (_signed);
}

void	FormA::beSigned(Bureaucrat const bur)
{
	if (bur.getGrade() <= (int)(this->_grade_sign))
	{
		std::cout << "signed : become true" << std::endl;
		this->_signed = true;
	}
	else
		throw FormA::GradeTooLowException();
}

FormA &FormA::operator=(FormA const &egal)
{	
	if (this != &egal)
	{
		this->_name = egal._name;
		this->_grade_exec = egal._grade_exec;
		this->_grade_sign = egal._grade_sign;
		this->_signed = egal._signed;
	}
	return (*this);
}

std::ostream    &operator<<(std::ostream &out, const FormA &FormA)
{
    out << FormA.getName() << "FormA grade to sign : " << FormA.getSignGrade() << " grade to exec :" << FormA.getExecGrade() << " signed : " << FormA.getbool() << std::endl;
    return (out);
}
