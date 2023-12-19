/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:03:51 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/18 10:01:53 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "FormA.hpp"

class ShrubberyCreationForm : public FormA
{
	public :
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	~ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm &test);
    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &egal);

	virtual void	execute(Bureaucrat const & executor) const;
	
	private :
	std::string _target;

};


#endif