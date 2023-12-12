/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ersees <ersees@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:58:52 by ersees            #+#    #+#             */
/*   Updated: 2023/12/10 20:06:11 by ersees           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char const **argv)
{
	Harl	test;

	if (argc != 2)
	{
		if (argc < 2)
			std::cerr << "not enough arguments" << std::endl;
		else
			std::cerr << "too many arguments" << std::endl;
		return (1);
	}

	test.complain(argv[1]);

	return (0);
}