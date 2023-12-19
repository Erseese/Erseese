/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:03:26 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/18 10:11:23 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "FormA.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public FormA
{
	public :
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	~RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm &test);
    RobotomyRequestForm &operator=(RobotomyRequestForm const &egal);
	virtual void	execute(Bureaucrat const & executor) const;


	private :
	std::string _target;

};


#endif