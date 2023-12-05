/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:42:05 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/04 13:13:25 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <cctype>

int	main(int argc, char **argv)
{
	int	t;

	t = 0;
	if (argc == 1)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n" , 0);
	while (++t < argc)
	{
		std::string arg = argv[t];
		std::transform(arg.begin(), arg.end(), arg.begin(), ::toupper);
		std::cout << arg;
	}
	std::cout << "\n";
	return (0);
}