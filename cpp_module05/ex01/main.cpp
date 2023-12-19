/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:35:54 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/17 17:53:42 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main ()
{
    try{
        Bureaucrat a(150, "Ersito");
        Form b(1, 1, "Ersitorform" );
		a.signForm(b);
        std::cout << b;
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }
    return 0;
}