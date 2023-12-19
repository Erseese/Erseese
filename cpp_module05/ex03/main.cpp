/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:35:54 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/18 12:49:01 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "FormA.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main ()
{
    try{
        Bureaucrat a(1, "Ersito");
        ShrubberyCreationForm b("Ersitorform");
		Intern someRandomIntern;
		FormA* rrf;
		rrf = someRandomIntern.MakeForm("Presidential Pardon", "Bender");
		a.signForm(*rrf);
		rrf->execute(a);
        std::cout << *rrf;
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }
    return 0;
}