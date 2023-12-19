/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:35:54 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/18 09:51:15 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "FormA.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main ()
{
    try{
        Bureaucrat a(1, "Ersito");
        ShrubberyCreationForm b("Ersitorform");
		a.signForm(b);
		b.execute(a);
        std::cout << b;
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }
    return 0;
}