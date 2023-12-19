/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:35:54 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/17 15:40:47 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main ()
{
    try
    { 
        // Bureaucrat a("a", 2);
        // std::cout << a.getGrade() << std::endl;
        // std::cout << a.getName() << std::endl;
        // a.incrementGrade();
        // std::cout << a.getGrade() << std::endl;
        // a.decrementGrade();
        // std::cout << a.getGrade() << std::endl;
        // a.incrementGrade();
        // a.incrementGrade();
        // 
        Bureaucrat a(150, "a");
        std::cout << a.getGrade() << std::endl;
        std::cout << a.getName() << std::endl;
        a.upgrade(2);
        std::cout << a.getGrade() << std::endl;
        a.downgrade(2);
        std::cout << a.getGrade() << std::endl;
        std::cout << a << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}