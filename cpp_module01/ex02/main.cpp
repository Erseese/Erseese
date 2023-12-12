/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:17:47 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/08 12:29:28 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iomanip>

int	main(void)
{
	std::string test = "HI THIS IS BRAIN";
	std::string *stringPTR = &test;
	std::string &stringREF = test;

	std::cout << &test << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;

	std::cout << test << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
}