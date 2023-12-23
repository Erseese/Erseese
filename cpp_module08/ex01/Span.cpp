/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:29:56 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/23 16:07:09 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Span.hpp"

Span::Span():_N(0)
{
	std::cout << "Default constructeur called" << std::endl;
}

Span::Span(unsigned int _N)
{
	std::cout << "constructeur" << std::endl;
	this->_N = _N;
}
Span::~Span()
{
	std::cout << "Destructeur" << std::endl;
}

Span::Span(const Span &test)
{
	*this = test;
}

void	Span::addNumber(int unsigned const toadd)
{
	int n = this->_Numbers.size();
	if (_N > n)
		this->_Numbers.push_back(toadd);
	else
		throw Span::TooMuchThings();
}

const char *Span::LessThenTwo::what() const throw()
{
	return ("U dont have enough number\n");
}
const char *Span::TooMuchThings::what() const throw()
{
	return ("Too much things\n");
}

int		Span::shortestSpan(void)
{
	int minSpan = 2147483647;
	int span = 2147483647;
	if (this->_N < 2 && this->_Numbers.size() < 2)
		throw (Span::LessThenTwo());
	else
	{
		
		std::vector<int> numbers = this->_Numbers;
		std::sort(numbers.begin(), numbers.end());
		for (int i = 1; i < numbers.size(); i++)
		{
			span = numbers[i] - numbers[i - 1];
			if (span < minSpan)
				minSpan = span;
		}
	}
	return minSpan;
}

int	Span::longestSpan()
{
	int min = 2147483647;
	int max = -1;
	if (this->_N < 2 && this->_Numbers.size() < 2)
		throw (Span::LessThenTwo());
	else
	{
		for (std::vector<int>::iterator i = _Numbers.begin(); i != _Numbers.end(); i++)
		{
			if (*i > max)
				max = *i;
			if (*i < min)
				min = *i;
		}
	}
	return (max - min);
}

Span &Span::operator=(Span const &egal)
{	
	if (this != &egal)
	{
		this->_N = egal._N;
		this->_Numbers = egal._Numbers;
	}
	return (*this);
}

template <typename T>
void Span::addNumbers(T begin, T end) 
{
	if (begin >= end)
		throw (std::out_of_range("sadge"));
	if (this->_Numbers.size() + (end - begin) > this->_N)
		throw TooMuchThings();
	this->_Numbers.insert(this->_Numbers.end(), begin, end);
}