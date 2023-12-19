/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:29:15 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/12 17:01:25 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <iomanip>
#include <iostream>

static void	printTitle(std::string title)
{
	std::string	toPrint;
	int	size = 60;
	int	n;

	toPrint = " " + title + " ";
	n = toPrint.size();
	if (n > size)
	{
		toPrint = toPrint.substr(0, size - 2);
		toPrint[size - 4] = '.';
		toPrint[size - 3] = ' ';
		n = toPrint.size();
	}
	std::cout << std::endl << std::setfill('=') << std::setw(size) << "" << std::endl;
	std::cout << std::setw(size / 2) << toPrint.substr(0, n / 2);
	std::cout << toPrint.substr(n / 2, n);
	std::cout << std::setfill('=') << std::setw(size - size / 2 - n + n / 2) << "" << std::endl;
	std::cout << std::setfill('=') << std::setw(size) << "" << std::endl;
}

static void	testLeaks(void)
{
	printTitle("LEAKS");
	const Animal	*dog = new Dog();
	const Animal	*cat = new Cat();

	delete dog;
	delete cat;
}

static void	testDeepCopy(void)
{
	printTitle("DEEP COPY");
	Dog	dog1;
	Dog	dog2;

	dog1.printIdeas();
	dog2.printIdeas();

	dog2 = dog1;
	std::cout << std::endl << "After assignation :" << std::endl;
	dog1.printIdeas();
	dog2.printIdeas();

	std::cout << std::endl;

	Cat	cat1;
	Cat	cat2(cat1);

	cat1.printIdeas();
	cat2.printIdeas();
}

static void	testSubject(int size)
{
	printTitle("SUBJECT");
	Animal	*arrayAnimals[2 * size];

	for (int i = 0; i < size; i++)
	{
		arrayAnimals[i] = new Dog();
		arrayAnimals[size + i] = new Cat();
	}

	for (int i = 0; i < 2 * size; i++)
		delete arrayAnimals[i];
}

int	main(void)
{
	testSubject(5);
	testLeaks();
	testDeepCopy();
	return (0);
}