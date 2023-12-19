/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 18:28:39 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/18 10:12:40 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "FormA.hpp"

class PresidentialPardonForm : public FormA
{
	public :
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	~PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm &test);
    PresidentialPardonForm &operator=(PresidentialPardonForm const &egal);
	virtual void	execute(Bureaucrat const & executor) const;


	private :
	std::string _target;

};


#endif