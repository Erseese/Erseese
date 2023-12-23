/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:21:04 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/20 18:25:28 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

template < typename T>
int easyfind(T &one, int second)
{
	for (std::vector<int>::iterator i = one.begin(); i != one.end(); i++)
	{
		if (*i == second)
			return (*i);
	}
	throw (std::out_of_range("flop"));
}

int	main(void)
{
	std::vector<int> numbers;
	numbers.push_back(1.3);
	numbers.push_back(100);
	numbers.push_back(10);
	numbers.push_back(70);
	numbers.push_back(2);
	numbers.insert(numbers.begin(), 7);
	std::vector<int>::iterator test = numbers.begin();
	
	try {
	int num2 = easyfind(numbers, 7);
	std::cout << num2 << std::endl;
	std::cout << test[1];
	}
	catch (const std::out_of_range &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	//std::cout << easyfind(numbers, num);
	return 0;
}