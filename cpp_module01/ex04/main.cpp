/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ersees <ersees@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 10:43:05 by ersees            #+#    #+#             */
/*   Updated: 2023/12/10 16:06:14 by ersees           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>
#include <fstream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (0);
	std::string nom_file = argv[1];
	std::string to_replace = argv[3];
	std::string replacedby = argv[2];
	std::string nouveau_file = nom_file + ".replace";
	std::ifstream original_file(nom_file.c_str());
	std::ofstream new_file(nouveau_file.c_str());
	size_t test = 0;
	std::string str;
	if (!new_file.is_open())
		return (0);
	if (original_file.is_open())
	{
		while (std::getline(original_file, str))
		{
			test = 0;
			while((str.find(to_replace, test)) != std::string::npos)
			{
				test = str.find(to_replace, test);
				str.erase(test, to_replace.length());
				str.insert(test, replacedby);
				test += replacedby.length();
			}
			new_file << str << std::endl;
			std::cout << str << std::endl;
		}
		original_file.close();
		new_file.close();
	}
}