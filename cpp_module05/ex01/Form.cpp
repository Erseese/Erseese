/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:40:51 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/17 17:52:11 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form():_name("Default"), _signed(false), _grade_sign(50), _grade_exec(75)
{
    std::cout << "Default constructeur called" << std::endl;
}

Form::Form(int grade_sign, int grade_exec, std::string name) 
{
	std::cout << "constructeur" << std::endl;
	if (grade_sign > 150 || grade_exec > 150)
		throw Form::GradeTooHighException();
	else if (grade_exec < 0 || grade_sign < 0)
		throw Form::GradeTooLowException();
	this->_grade_sign = grade_sign;
	this->_grade_exec = grade_exec;
	this->_signed = false;
	this->_name = name;
}
Form::~Form()
{
	std::cout << "Destructeur" << std::endl;
}

Form::Form(const Form &test)
{
	*this = test;
}

std::string	Form::getName(void) const
{
	std::cout << "Name : " << _name << std::endl;
	return (_name);
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("ptit flop de ta part tu feras mieux la prochaien fois trop haut\n");
}
const char *Form::GradeTooLowException::what() const throw()
{
	return ("ptit flop de ta part tu feras mieux la prochaien fois trop bas\n");
}

int		Form::getExecGrade(void) const
{
	std::cout << "Grade exec : " << _grade_exec << std::endl;
	return (_grade_exec);
}
int		Form::getSignGrade(void) const
{
	std::cout << "Grade sign : " << _grade_sign << std::endl;
	return (_grade_sign);
}

bool		Form::getbool(void) const
{
	std::cout << "bool : " << _signed << std::endl;
	return (_signed);
}

void	Form::beSigned(Bureaucrat const bur)
{
	if (bur.getGrade() <= (int)(this->_grade_sign))
	{
		std::cout << "signed : become true" << std::endl;
		this->_signed = true;
	}
	else
		throw Form::GradeTooLowException();
}

Form &Form::operator=(Form const &egal)
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

std::ostream    &operator<<(std::ostream &out, const Form &Form)
{
    out << Form.getName() << "Form grade to sign : " << Form.getSignGrade() << " grade to exec :" << Form.getExecGrade() << " signed : " << Form.getbool() << std::endl;
    return (out);
}
