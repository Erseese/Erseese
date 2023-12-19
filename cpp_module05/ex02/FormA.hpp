/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FormA.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:40:54 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/18 10:00:24 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMA_HPP
#define FORMA_HPP

#include "Bureaucrat.hpp"
#include <fstream>
#include <string>

class Bureaucrat;

class FormA{

public :
	FormA();
    FormA(int grade_sign, int grade_exec, std::string name);
    ~FormA();
	void	beSigned(Bureaucrat const bur);
	int		getSignGrade(void) const;
	int		getExecGrade(void) const;
	bool	getbool(void) const;
	std::string	getName(void) const;
    FormA(const FormA &test);
    FormA &operator=(FormA const &egal);
	class GradeTooHighException : public std::exception 
	{
		public :
			virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception 
	{
		public :
			virtual const char* what() const throw();
	};
	class NotSigned : public std::exception 
	{
		public :
			virtual const char* what() const throw();
	};
	virtual void	execute(Bureaucrat const & executor) const = 0;

private :
	std::string		_name;
	bool			_signed;
	unsigned int	_grade_sign;
	unsigned int	_grade_exec;

};
std::ostream &operator<<(std::ostream &out, const FormA &FormA);

#endif