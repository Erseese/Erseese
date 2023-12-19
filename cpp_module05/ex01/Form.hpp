/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:40:54 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/17 17:48:43 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{

public :
	Form();
    Form(int grade_sign, int grade_exec, std::string name);
    ~Form();
	void	beSigned(Bureaucrat const bur);
	int		getSignGrade(void) const;
	int		getExecGrade(void) const;
	bool	getbool(void) const;
	std::string	getName(void) const;
    Form(const Form &test);
    Form &operator=(Form const &egal);
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
	bool			_signed;
	unsigned int	_grade_sign;
	unsigned int	_grade_exec;

};
std::ostream &operator<<(std::ostream &out, const Form &Form);

#endif