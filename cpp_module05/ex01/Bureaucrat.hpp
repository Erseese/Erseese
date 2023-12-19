/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:31:32 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/17 17:50:15 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat{

public :
	Bureaucrat();
    Bureaucrat(int grade, std::string name);
    ~Bureaucrat();
	void	downgrade(int unsigned const grade);
	void	upgrade(int unsigned const grade);
	int		getGrade(void) const;
	std::string	getName(void) const;
    Bureaucrat(const Bureaucrat &test);
    Bureaucrat &operator=(Bureaucrat const &egal);
	void	signForm(Form form);
	class GradeTooHighException : public std::exception {
	public :
		virtual const char* what() const throw();
	};
class GradeTooLowException : public std::exception {
	public :
		virtual const char* what() const throw();
};

private :
	std::string		_name;
	unsigned int	_grade;

};
std::ostream &operator<<(std::ostream &out, const Bureaucrat &Bureaucrat);

#endif